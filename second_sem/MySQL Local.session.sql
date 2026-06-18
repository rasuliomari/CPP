-- Create a new database
CREATE DATABASE companyData2026;
SHOW DATABASES;

-- Switch to a specific database
USE companyData2026;


-- Create a new table
CREATE TABLE  tbDepartment ( 
    DeptNo int NOT NULL PRIMARY KEY, 
    DeptName varchar (50) NOT NULL UNIQUE, 
    mgrSSN bigint  not null, 
    MgrStartDate date not null );

CREATE TABLE tbEmployee ( 
    SSN int not NULL, 
    fName Varchar (45) not null, 
    mName varchar (45), 
    Surname Varchar (45) not null, 
    Sex varchar (2) Not null CHECK(Sex IN ('M','F')), 
    EmpAddress varchar (60) not null, 
    Salary float CHECK (Salary BETWEEN 100000 AND 10000000), 
    DeptNo int, 
    mgrSSN int, 
    constraint foreign key  (mgrSSN) REFERENCES tbEmployee (SSN), 
    constraint FOREIGN KEY (DeptNo) REFERENCES tbDepartment (DeptNo) ON UPDATE CASCADE ON DELETE NO ACTION, 
    PRIMARY KEY (SSN) );

CREATE TABLE tbProject ( 
    pNumber int not null Primary Key, 
    pName varchar(45) not null UNIQUE, 
    pLocation varchar (45) not null, 
    Budget float not null, 
    DeptNo int, 
    constraint foreign key (DeptNo) references tbDepartment(DeptNo) ON UPDATE NO ACTION ON delete NO ACTION );

CREATE TABLE tbWorkson ( 
    pNumber int not null, 
    SSN int not null , 
    NoHours float not null, 
    PRIMARY KEY (pNumber,SSN), 
    constraint foreign key (pNumber) references tbProject(pNumber) ON UPDATE CASCADE ON DELETE NO ACTION, 
    constraint foreign key (SSN) references tbEmployee (SSN) ON UPDATE CASCADE ON DELETE NO ACTION ); 

CREATE TABLE tbDependant (  
    SSN  int not NULL,  
    dfName varchar (45) not null,  
    dmName VARCHAR (45),  
    dSurname varchar (45) not null,  
    Sex varchar (2) NOT NULL CHECK (SEX IN ('M','F')),  
    DateofBirth date,  
    Relationship varchar (50) not null,  
    PRIMARY KEY (SSN, dfName), 
    constraint FOREIGN KEY (SSN) REFERENCES tbEmployee (SSN) ON DELETE CASCADE ON UPDATE CASCADE  );

CREATE TABLE tbLocation ( 
    DeptNo int NOT NULL , 
    DeptLocation Varchar (45) NOT NULL , 
    PRIMARY KEY (DeptNo,DeptLocation), 
    constraint foreign key  (DeptNo) REFERENCES tbDepartment(DeptNo) ON UPDATE CASCADE ON DELETE NO ACTION );

ALTER TABLE tbDepartment 
ADD constraint FOREIGN KEY (mgrSSN) REFERENCES tbEmployee(SSN) 
ON UPDATE CASCADE ON DELETE CASCADE;

ALTER TABLE tbDepartment DROP CONSTRAINT FK_person;

ALTER TABLE tbDepartment ADD CONSTRAINT FK_person FOREIGN KEY (mgrSSN) REFERENCES tbEmployee(SSN);

-- Select all records from the table
Select * from tbEmployee;
Select * FROM tbProject;  
Select * from tbWorkson;
Select * from tbDependant;
Select * from tbLocation;
select * from tbDepartment;

-- Adding column 
ALTER TABLE tbEmployee
  ADD COLUMN DoB DATE AFTER Surname;

ALTER TABLE tbProject
  ADD COLUMN Status VARCHAR(20) DEFAULT 'Active'
    CHECK (Status IN ('Active', 'Completed', 'On Hold'));

ALTER TABLE tbDepartment
  ADD COLUMN DeptPhone VARCHAR(20);

-- describe the modified table
DESC tbEmployee;
DESC tbProject;
DESC tbDepartment;

-- modifying an existing column
ALTER TABLE tbEmployee
  MODIFY COLUMN Salary DECIMAL(12,2)
    CHECK (Salary BETWEEN 100000 AND 10000000);

ALTER TABLE tbDepartment
  MODIFY COLUMN DeptName VARCHAR(80) NOT NULL;

-- Renaming a column
ALTER TABLE tbDepartment
  RENAME COLUMN DeptPhone TO ContactNumber;

--Droping a column
ALTER TABLE tbDepartment
  DROP COLUMN ContactNumber;

ALTER TABLE tbEmployee
  DROP COLUMN DeptNo; --Cannot drop index 'DeptNo': needed in a foreign key constraint

SELECT CONSTRAINT_NAME
FROM   INFORMATION_SCHEMA.KEY_COLUMN_USAGE
WHERE  TABLE_SCHEMA = 'CompanyDatabase2026'
  AND  TABLE_NAME   = 'tbEmployee'
  AND  COLUMN_NAME  = 'DeptNo';

-- Inserting records into the table Departments
INSERT INTO tbDepartment (DeptNo, DeptName, mgrSSN, MgrStartDate) VALUES
(1, 'Research',        333445555, '2018-06-01'),
(2, 'Administration',  453453453, '2017-03-15'),
(3, 'Headquarters',    888665555, '2010-01-01'),
(4, 'ICT',             666884444, '2019-01-10');

INSERT INTO tbEmployee (SSN, fName, mName, Surname, Sex, EmpAddress, Salary, DeptNo, mgrSSN)
VALUES
  (888665555, 'Asha',  NULL,  'Smith',   'F', 'Box 457, Tanga',          2000000, 3, NULL),
  (333445555, 'John',  'B.',  'Doe',     'M', 'Box 123, Dodoma',          1800000, 1, 888665555),
  (453453453, 'Grace', 'K.',  'Mwamba',  'F', 'Box 222, Dar es Salaam',   1600000, 2, 888665555),
  (666884444, 'Peter', 'M.',  'Nkosi',   'M', 'Box 101, Dodoma',          1700000, 4, 888665555),
  (123456789, 'Alice', NULL,  'Johnson', 'F', 'Box 789, Arusha',          1500000, 1, 333445555),
  (987654321, 'James', NULL,  'Osei',    'M', 'Box 333, Mwanza',          1400000, 2, 453453453),
  (543210987, 'Lena',  NULL,  'Cruz',    'F', 'Box 555, Moshi',           1300000, 4, 666884444),
  (999000111, 'Demo',  NULL,  'Baraka',  'M', 'Box 999, Dodoma',          1200000, 2, 453453453);

INSERT INTO tbProject (pNumber, pName, pLocation, Budget, DeptNo) VALUES
  (1, 'ProductX',        'Dodoma',        5000000.00, 1),
  (2, 'ProductY',        'Arusha',        8000000.00, 1),
  (3, 'Computerisation', 'Dar es Salaam', 3000000.00, 2),
  (4, 'Reorganisation',  'Dodoma',        2000000.00, 2),
  (5, 'NewBenefits',     'Mwanza',        4500000.00, 4);

INSERT INTO tbLocation (DeptNo, DeptLocation) VALUES
  (1, 'Dodoma'), (1, 'Arusha'),
  (2, 'Dodoma'), (2, 'Mwanza'),
  (3, 'Dar es Salaam'),
  (4, 'Dodoma');

INSERT INTO tbWorkson (pNumber, SSN, NoHours) VALUES
  (1, 123456789, 32.5),
  (1, 333445555,  7.5),
  (2, 333445555, 10.0),
  (2, 666884444, 10.0),
  (3, 453453453, 20.0),
  (3, 987654321, 35.0),
  (4, 888665555, 20.0),
  (4, 987654321,  5.0),
  (5, 666884444, 20.0),
  (5, 543210987, 15.0),
  (5, 888665555, 10.0);

INSERT INTO tbDependant (SSN, dfName, dmName, dSurname, Sex, DateofBirth, Relationship)
VALUES
  (333445555, 'Alice',   NULL, 'Doe',     'F', '1990-04-05', 'Daughter'),
  (333445555, 'Tom',     NULL, 'Doe',     'M', '1992-10-25', 'Son'),
  (888665555, 'Michael', NULL, 'Smith',   'M', '1975-08-20', 'Spouse'),
  (123456789, 'Grace',   NULL, 'Johnson', 'F', '2015-06-12', 'Daughter'),
  (666884444, 'Joy',     NULL, 'Nkosi',   'F', '2010-03-30', 'Daughter'),
  (999000111, 'Babu',    NULL, 'Baraka',  'M', '2019-07-01', 'Son');

-- Verify all inserted records
SELECT * FROM tbDepartment;
SELECT * FROM tbEmployee;
SELECT * FROM tbProject;
SELECT * FROM tbLocation;
SELECT * FROM tbWorkson;

-- The Truncate command
SELECT * FROM tbDependant;

TRUNCATE TABLE tbDependant;

SELECT * FROM tbDependant;

INSERT INTO tbDependant (SSN, dfName, dmName, dSurname, Sex, DateofBirth, Relationship)
VALUES
  (333445555, 'Alice',   NULL, 'Doe',     'F', '1990-04-05', 'Daughter'),
  (333445555, 'Tom',     NULL, 'Doe',     'M', '1992-10-25', 'Son'),
  (888665555, 'Michael', NULL, 'Smith',   'M', '1975-08-20', 'Spouse'),
  (123456789, 'Grace',   NULL, 'Johnson', 'F', '2015-06-12', 'Daughter'),
  (666884444, 'Joy',     NULL, 'Nkosi',   'F', '2010-03-30', 'Daughter'),
  (999000111, 'Babu',    NULL, 'Baraka',  'M', '2019-07-01', 'Son');

-- Attempting to Truncate a parent table (restricted case)
TRUNCATE TABLE tbEmployee; -- This will fail due to foreign key constraints

TRUNCATE TABLE tbDepartment; -- This will succeed as it has no dependent tables

-- CASCADE AND NO ACTION
SELECT SSN, pNumber, NoHours      FROM tbWorkson   WHERE SSN = 666884444;
SELECT SSN, dfName, Relationship FROM tbDependant WHERE SSN = 666884444;

UPDATE tbEmployee SET SSN = 777777777 WHERE SSN = 666884444;

SELECT SSN, pNumber, NoHours      FROM tbWorkson   WHERE SSN = 777777777;
SELECT SSN, dfName, Relationship FROM tbDependant WHERE SSN = 777777777;

-- Observe ON DELETE CASCADE
SELECT * FROM tbDependant WHERE SSN = 999000111;
SELECT * FROM tbWorkson  WHERE SSN = 999000111;

DELETE FROM tbEmployee WHERE SSN = 999000111;

UPDATE tbDepartment SET DeptNo = 10 WHERE DeptNo = 1; -- This will update DeptNo in tbDepartment and cascade the change to tbEmployee, tbProject, and tbLocation

DELETE FROM tbDepartment WHERE DeptNo = 2; -- This will delete the department and cascade the delete to tbEmployee, tbProject, and tbLocation, but will fail if there are dependent records in tbWorkson or tbDependant due to NO ACTION constraints

