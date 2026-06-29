-- Create the CyberAgency database
CREATE DATABASE CyberAgency;
-- Use the CyberAgency database
USE CyberAgency;


-- 1. Organization Table
CREATE TABLE Organization (
    OrgID VARCHAR(20) PRIMARY KEY,
    Name VARCHAR(100) NOT NULL,
    Type VARCHAR(50) NOT NULL CHECK (Type IN ('Government', 'Financial Institution', 'Healthcare Provider', 'Education Institution', 'Private Business')),
    Address VARCHAR(255) NOT NULL,
    Email VARCHAR(100) NOT NULL
);

-- 2. OrganizationPhone Table
CREATE TABLE OrganizationPhone (
    OrgID VARCHAR(20),
    PhoneNumber VARCHAR(20),
    PRIMARY KEY (OrgID, PhoneNumber),
    FOREIGN KEY (OrgID) REFERENCES Organization(OrgID) ON DELETE CASCADE
);

-- 3. IndividualReporter Table
CREATE TABLE IndividualReporter (
    ReporterID VARCHAR(20) PRIMARY KEY,
    FullName VARCHAR(100) NOT NULL,
    NationalID VARCHAR(20) NOT NULL UNIQUE,
    Address VARCHAR(255) NOT NULL,
    Email VARCHAR(100) NOT NULL,
    Phone VARCHAR(20) NOT NULL
);

-- 4. Incident Table
CREATE TABLE Incident (
    IncidentID VARCHAR(20) PRIMARY KEY,
    Title VARCHAR(100) NOT NULL,
    Category VARCHAR(50) NOT NULL CHECK (Category IN ('Malware Attack', 'Ransomware', 'Phishing', 'Unauthorized Access', 'Data Breach', 'Denial of Service', 'Insider Attack')),
    Description TEXT NOT NULL,
    DateReported DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    SeverityLevel VARCHAR(10) NOT NULL CHECK (SeverityLevel IN ('Low', 'Medium', 'High', 'Critical')),
    ReportingMethod VARCHAR(30) NOT NULL CHECK (ReportingMethod IN ('Email', 'Phone Call', 'Physical Visit', 'Online Portal Submission')),
    OrgID VARCHAR(20) NULL,
    ReporterID VARCHAR(20) NULL,
    FOREIGN KEY (OrgID) REFERENCES Organization(OrgID),
    FOREIGN KEY (ReporterID) REFERENCES IndividualReporter(ReporterID)
);

-- 5. AffectedSystem Table
CREATE TABLE AffectedSystem (
    SystemID VARCHAR(20) PRIMARY KEY,
    SystemName VARCHAR(100) NOT NULL,
    SystemType VARCHAR(50) NOT NULL CHECK (SystemType IN ('Server', 'Workstation', 'Mobile Device', 'Network Device', 'Cloud Service')),
    OperatingSystem VARCHAR(50) NOT NULL,
    IPAddress VARCHAR(45) NOT NULL,
    PhysicalLocation VARCHAR(100) NOT NULL
);


-- 6. IncidentSystem Table (Associative)
CREATE TABLE IncidentSystem (
    IncidentID VARCHAR(20),
    SystemID VARCHAR(20),
    DateDetected DATETIME NOT NULL,
    DateRestored DATETIME NULL,
    PRIMARY KEY (IncidentID, SystemID),
    FOREIGN KEY (IncidentID) REFERENCES Incident(IncidentID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (SystemID) REFERENCES AffectedSystem(SystemID) ON DELETE CASCADE ON UPDATE CASCADE
);

-- 7. Investigator Table
CREATE TABLE Investigator (
    InvestigatorID VARCHAR(20) PRIMARY KEY,
    FullName VARCHAR(100) NOT NULL,
    Rank VARCHAR(50) NOT NULL,
    AreaOfResponsibility VARCHAR(100) NOT NULL,
    Phone VARCHAR(20) NOT NULL,
    Email VARCHAR(100) NOT NULL,
    EmploymentDate DATE NOT NULL
);

-- 8. InvestigatorAssignment Table (Associative)
CREATE TABLE InvestigatorAssignment (
    IncidentID VARCHAR(20),
    InvestigatorID VARCHAR(20),
    AssignmentDate DATE NOT NULL,
    Role VARCHAR(50) NOT NULL CHECK (Role IN ('Lead Investigator', 'Forensic Analyst', 'Incident Responder')),
    PRIMARY KEY (IncidentID, InvestigatorID),
    FOREIGN KEY (IncidentID) REFERENCES Incident(IncidentID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (InvestigatorID) REFERENCES Investigator(InvestigatorID) ON DELETE CASCADE ON UPDATE CASCADE
);

-- 9. Evidence Table
CREATE TABLE Evidence (
    EvidenceID VARCHAR(20) PRIMARY KEY,
    EvidenceType VARCHAR(50) NOT NULL CHECK (EvidenceType IN ('Hard Disk Image', 'Log File', 'Network Packet Capture', 'Mobile Phone Dump', 'USB Device', 'Screenshot', 'Email File', 'Malware Sample')),
    Description VARCHAR(255) NOT NULL,
    DateCollected DATETIME NOT NULL,
    CollectionLocation VARCHAR(100) NOT NULL,
    HashValue CHAR(64) NOT NULL,
    StorageLocation VARCHAR(100) NOT NULL,
    IncidentID VARCHAR(20) NOT NULL,
    SystemID VARCHAR(20) NULL,
    FOREIGN KEY (IncidentID) REFERENCES Incident(IncidentID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (SystemID) REFERENCES AffectedSystem(SystemID) ON DELETE SET NULL ON UPDATE CASCADE
);

-- 10. EvidenceCopy Table
CREATE TABLE EvidenceCopy (
    EvidenceID VARCHAR(20),
    CopyNumber INT,
    Purpose VARCHAR(100) NOT NULL,
    PRIMARY KEY (EvidenceID, CopyNumber),
    FOREIGN KEY (EvidenceID) REFERENCES Evidence(EvidenceID) ON DELETE CASCADE ON UPDATE CASCADE
);

-- 11. ChainOfCustody Table
CREATE TABLE ChainOfCustody (
    CustodyID VARCHAR(20) PRIMARY KEY,
    EvidenceID VARCHAR(20) NOT NULL,
    TransferredBy VARCHAR(20) NOT NULL,
    ReceivedBy VARCHAR(20) NOT NULL,
    TransferDateTime DATETIME NOT NULL,
    Reason VARCHAR(255) NOT NULL,
    FOREIGN KEY (EvidenceID) REFERENCES Evidence(EvidenceID),
    FOREIGN KEY (TransferredBy) REFERENCES Investigator(InvestigatorID),
    FOREIGN KEY (ReceivedBy) REFERENCES Investigator(InvestigatorID)
);

-- 12. Laboratory Table
CREATE TABLE Laboratory (
    LabID VARCHAR(20) PRIMARY KEY,
    LabName VARCHAR(100) NOT NULL,
    Location VARCHAR(100) NOT NULL,
    ContactNumber VARCHAR(20) NOT NULL
);

-- 13. ForensicAnalysis Table
CREATE TABLE ForensicAnalysis (
    AnalysisID VARCHAR(20) PRIMARY KEY,
    EvidenceID VARCHAR(20) NOT NULL,
    LabID VARCHAR(20) NOT NULL,
    InvestigatorID VARCHAR(20) NOT NULL,
    AnalysisDate DATE NOT NULL,
    AnalysisMethod VARCHAR(50) NOT NULL CHECK (AnalysisMethod IN ('Disk Imaging', 'Log Analysis', 'Memory Analysis', 'Malware Reverse Engineering', 'Network Analysis')),
    Findings TEXT NOT NULL,
    FOREIGN KEY (EvidenceID) REFERENCES Evidence(EvidenceID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (LabID) REFERENCES Laboratory(LabID),
    FOREIGN KEY (InvestigatorID) REFERENCES Investigator(InvestigatorID)
);

-- 14. ExternalAgency Table
CREATE TABLE ExternalAgency (
    AgencyID VARCHAR(20) PRIMARY KEY,
    AgencyName VARCHAR(100) NOT NULL,
    AgencyType VARCHAR(50) NOT NULL,
    ContactPerson VARCHAR(100) NOT NULL,
    Email VARCHAR(100) NOT NULL,
    Phone VARCHAR(20) NOT NULL
);


-- 15. Collaboration Table (Associative)
CREATE TABLE Collaboration (
    IncidentID VARCHAR(20),
    AgencyID VARCHAR(20),
    CommunicationDate DATE,
    RequestType VARCHAR(255) NOT NULL,
    ResponseReceived TEXT NULL,
    PRIMARY KEY (IncidentID, AgencyID, CommunicationDate),
    FOREIGN KEY (IncidentID) REFERENCES Incident(IncidentID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (AgencyID) REFERENCES ExternalAgency(AgencyID) ON DELETE CASCADE ON UPDATE CASCADE
);

-- 16. CaseReport Table
CREATE TABLE CaseReport (
    ReportID VARCHAR(20) PRIMARY KEY,
    IncidentID VARCHAR(20) UNIQUE NOT NULL,
    ReportDate DATE NOT NULL,
    SummaryOfFindings TEXT NOT NULL,
    RecommendedActions TEXT NOT NULL,
    LegalStatus VARCHAR(50) NOT NULL CHECK (LegalStatus IN ('Under Investigation', 'Forwarded to Prosecution', 'Closed with no action', 'Resolved')),
    CourtCaseRef VARCHAR(50) NULL,
    CourtName VARCHAR(100) NULL,
    CaseStatus VARCHAR(50) NULL,
    FOREIGN KEY (IncidentID) REFERENCES Incident(IncidentID) ON DELETE CASCADE ON UPDATE CASCADE
);
