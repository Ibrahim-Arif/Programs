create database SP19_BCS_033_C;
use SP19_BCS_033_C;

create table salesman( id int primary key,
					   name varchar(20),
                       salary int
					 );

create table customer( id int primary key,
					   name varchar(20),
                       industry_type char(5)
					 );

create table product1( prod_no int primary key, 
					   order_date varchar(20),
                       cust_id int,
                       salesman_id int,
                       amount int,
                      
                       foreign key (cust_id) references customer(id),
                       foreign key(salesman_id) references salesman(id)
					 );
 
SELECT * FROM salesman;
SELECT * FROM customer;
SELECT * FROM product1;



-- 1.  Display customer id, industry type and number of orders of those products  
--     where at least two products are ordered by SAMSONIC)
SELECT 
	customer.id, 
    customer.industry_type, 
    count(*)
FROM customer
WHERE (
		SELECT count(*)
		FROM product1
		WHERE cust_id = (	
							SELECT customer.id 
                            FROM customer 
                            WHERE name = 'samsonic'
						)
	  ) >= 2;


-- 2. Display the names of those salesman whose salary is 
--    more than 25000 after giving 20% increment
SELECT 
	name
FROM salesman
WHERE (salary + 0.2*salary) > 25000;

-- 3. Display the number, amount and order date of those products 
--    whose amount is greater than Bob’s salary. 
SELECT
	prod_no, 
    amount, 
    order_date
FROM product1
WHERE amount > ( 
					SELECT salary
					FROM salesman
					WHERE name = 'bob'
			   );
    
-- 4. Display the order date and customer id of 
--    those products if there exist a salesman Id greater than 5. 
SELECT 
	order_date, 
    customer.id
FROM product1
JOIN customer
ON customer.id = product1.cust_id
WHERE EXISTS ( 
				SELECT salesman.id 
                FROM salesman 
                WHERE id > 5 
			 );

-- 5. Display customer id, name, product order date, amount and salesman name 
--    of all products whether or not customer ordered any product. 
SELECT 
	customer.id, 
    customer.name, 
    product1.order_date, 
    product1.amount, 
    salesman.name
FROM customer
LEFT JOIN product1
ON product1.cust_id = customer.id
LEFT JOIN salesman
ON salesman.id = product1.salesman_id;

-- 6. Display all products number and amount which are ordered by customer named Samony.
SELECT 
	prod_no, 
    amount
FROM product1
WHERE cust_id IN (	
					SELECT id 
					FROM customer 
                    WHERE name = 'Samony'
				 );