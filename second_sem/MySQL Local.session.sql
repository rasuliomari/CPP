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


