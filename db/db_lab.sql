create database DB_LAB;
use DB_LAB;
desc employee;

delete from employee;
drop table employee;

SELECT * FROM employee;
INSERT INTO employee(ename, job, salary, deptno)
VALUES('javaid', 'manager' , 20000, 1),
	('ahmed', 'salesman' , 25000, 2),
    ('arslan', 'analyst' , 35000, 3),
    ('memona', 'manager' , 40000, 2),
	('sara', 'salesman' , 10000, 1);
    
CREATE TABLE employee(
	empid   int 			auto_increment primary key, 
	eName   varchar(50), 
	job     varchar(50)  	not null, 
	salary  int, 
	deptNo  int, 			foreign key (deptNo) references dept (deptNo)
);

SELECT * FROM dept;
INSERT INTO dept(dname)
VALUES('CS'), ('Accounting'), ('Finance');
CREATE TABLE dept(
	deptNo 	int 			AUTO_INCREMENT PRIMARY KEY, 
	dName 	varchar(10)
);

ALTER TABLE employee
ADD CONSTRAINT salaryCheck check(salary>=10000 and salary <=90000);

ALTER TABLE employee
DROP COLUMN salary;

ALTER TABLE dept
MODIFY COLUMN dname varchar(50) NOT NULL;

SELECT employee.eName AS employee_name, employee.deptNo, dept.dname
FROM employee
JOIN dept
ON employee.deptNo = dept.deptNo
where dName = 'CS';

SELECT employee.eName, employee.salary
FROM employee
WHERE salary BETWEEN 20000 and 90000;

SELECT employee.eName, employee.empid 
FROM employee
WHERE eName LIKE 'a%'
AND salary > 30000;

SELECT employee.eName, employee.job
FROM employee
WHERE eName LIKE '%c%';

   
SELECT job, INSTR(job, 'n') AS 'n\'s position'
FROM employee;

SELECT eName, 
	salary AS 'original', 
	replace(salary, 35000, 20000) AS '35k to 20k'
FROM employee;

SELECT upper(eName) AS 'Name', char_length(eName) AS 'length'
FROM employee
WHERE eName LIKE 'j%' 
   OR eName LIKE 'a%' 
   OR eName LIKE 'm%'
ORDER BY eName;

SELECT concat(upper(eName), ' - ', job) AS 'E-JOB'
FROM employee
where char_length(concat(eName, job)) > 10;

SELECT eName, substr(reverse(eName), 2,1) AS '2nd last char'
FROM employee;

select now() as 'Current data, time';

SELECT eName, substr(eName, -2, 1) AS '2nd last char'
from employee;


SELECT deptNo, avg(salary) AS 'AVG'
FROM employee
GROUP BY deptNo;

SELECT deptNo, max(salary)
FROM employee
GROUP BY deptNo
HAVING max(salary) > 11000
ORDER BY deptNo DESC;

SELECT empid, eName, salary, (0.15*salary)+salary AS 'NEW_SALARY'
FROM employee;

SELECT empid, avg(salary) AS 'AVG'
FROM employee
WHERE deptno BETWEEN 1 AND 8
GROUP BY deptno
HAVING avg(salary) > 9000;


SELECT count(*) AS 'Count'
FROM employee
HAVING count(*) > 3;

SELECT min(salary)
FROM employee
GROUP BY deptno
HAVING min(salary) > 5000;

-- simple join or inner join
SELECT ename, dname
FROM employee
JOIN dept
ON employee.deptno = dept.deptno;

-- simple join, printing all employee having salary > 10000
SELECT job, dname, dept.deptno
FROM employee
JOIN dept
ON employee.deptno = dept.deptno
WHERE salary > 10000;

-- simple join, printing all employee exact from sales dept
SELECT eName, job, salary, dept.dname
FROM employee
JOIN dept
ON employee.deptNo = dept.deptNo
WHERE dept.dName != 'SALES';

-- simple join, and printing total number of employee with same dept, and avg salary of dept.
SELECT 
	dept.dname, 
    count(*) AS total_emp,
    sum(employee.salary) / count(*) AS avg_salary
FROM dept
JOIN employee
ON dept.deptNo = employee.deptNo
GROUP BY dept.dname;

-- right join
SELECT 
	dept.dname, 
	dept.deptNo, 
    count(*) AS total_emp
FROM dept
RIGHT JOIN employee
ON dept.deptNo = employee.deptNo
GROUP BY dept.deptno;

-- complete join (left, right)
SELECT
	employee.ename,
	dept.dname
FROM employee
LEFT JOIN dept
	ON dept.deptNo = employee.deptNo
UNION ALL
SELECT
	employee.ename,
	dept.dname
FROM employee
RIGHT JOIN dept
	ON dept.deptNo = employee.deptNo;

-- left join
SELECT
	dept.dname,
	employee.ename
FROM dept
LEFT JOIN employee
ON dept.deptNo = employee.deptNo;

-- self join.. 
SELECT
	e2.eName,
    e2.salary
FROM employee e1, 
	 employee e2
WHERE 
	e1.eName = 'ahmed' 
		AND 
	e2.salary > e1.salary;


SELECT deptno, salary
FROM employee
WHERE salary IN ( 
					SELECT salary
					FROM employee
					WHERE job = 'manager'
				 );

SELECT deptno, ename
FROM employee
WHERE salary < ANY ( 
						SELECT salary
						FROM employee
						WHERE job = 'manager'
					)
;

SELECT ename
FROM employee
WHERE salary >= ALL (
						SELECT salary
						FROM employee
						WHERE job = 'analyst'
					)
;

SELECT ename
FROM employee
WHERE deptno = ANY (
						SELECT deptno
						FROM employee
						WHERE ename = 'john'	
				   )
;

SELECT ename
FROM employee
WHERE EXISTS (
				SELECT ename
                FROM employee
                WHERE job = 'manager'
			 )
;

-- ASSIGNMENT 3 --

SELECT empid, eName
FROM employee
WHERE deptNo IN (
					SELECT deptNo
                    FROM employee
                    WHERE eName LIKE '%T%'
				)
;

SELECT *
FROM employee
WHERE EXISTS(
	SELECT 1
    FROM employee
    WHERE deptNo = (
		SELECT deptNo
        FROM dept
        WHERE dname = 'sales'
    )
);

SELECT *
FROM employee
WHERE salary < ANY (
	SELECT salary
    FROM employee
    WHERE job = 'analyst'
);

select * from dept;
select * from employee;

SELECT deptNo, avg(salary)
FROM employee
GROUP BY deptNo
HAVING avg(salary) < (
	SELECT avg(salary) 
	FROM employee
);

UPDATE employee
SET salary = salary + salary*0.5
WHERE deptNo >= 20;