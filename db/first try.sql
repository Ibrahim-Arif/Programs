create database db1;

CREATE TABLE employee(
	empid   int 			auto_increment primary key, 
	eName   varchar(10), 
	job     varchar(10)  	not null, 
	salary  int, 			check(salary>=10000 and salary <=90000), 
	deptNo  int, 			foreign key (deptNo) references dept (deptNo)
);
CREATE TABLE dept(
	deptNo 	int 			AUTO_INCREMENT PRIMARY KEY, 
	dName 	varchar(10) 	not null
);

DESCRIBE employee;
DROP TABLE employee;

ALTER TABLE employee 
DROP COLUMN job;

ALTER TABLE employee 
ADD job varchar(10) not null;

SELECT * FROM employee;
INSERT INTO employee(eName, job, salary, deptNo)
VALUES ('ibrahim', 'developer', 90000, 2);

SELECT *FROM dept;
INSERT INTO dept(dName)
VALUES ('finance');

UPDATE employee
SET eName = 'ibrahim'
WHERE employee.empid = 102;

DELETE FROM employee
WHERE empid <> 102;

SELECT eName, job
FROM employee
WHERE job = 'analyst'
ORDER BY empid DESC
LIMIT 1;


