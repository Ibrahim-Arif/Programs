create database sp19_bcs_033_c;
use sp19_bcs_033_c;

create table author(
	author_id int primary key,
    author_name varchar(20)
);

create table publisher(
	publisher_id int primary key,	
	publisher_name varchar(20)
);

create table book1(
	book_id int primary key,
    ISBN varchar(20),
    publisher_id int,
    Title varchar(20),
    author_id int,
	price int,
    
    Foreign key(publisher_id) references publisher(publisher_id),
	Foreign key(author_id) references author(author_id),
	Foreign key(publisher_id) references publisher(publisher_id)
);

Insert into author values(40,'James');
Insert into author values(50,'Scott');
Insert into author values(60,'David');
insert into author values(70,'Stuart');

Insert into publisher values(131,'Lap Lambert');
Insert into publisher values(132,'Thomson Reuters');
Insert into publisher values(133,'Wiley');

Insert into book1 values(1,'999-17-129',131,'database',40,5000);
Insert into book1 values(2,'989-11-143',132,'Ride sharing system',50,2000);
Insert into book1 values(3,'965-12-133',133,'Performance Evaluation System',50,1000);
Insert into book1 values(4,'987-15-276',133,'OOP concepts',60,7000);
insert into book1 values(5,'999-17-281',133,'Mathematics',60,7000);


SELECT * FROM author;
SELECT * FROM publisher;
SELECT * FROM book1;



-- 1
SELECT 
	book1.book_id, 
    book1.title, 
    book1.price
FROM book1
WHERE book1.price > (
						SELECT min(price) 
                        FROM book1
					) 
		AND 
	book1.price < 3000;
    
-- 2
SELECT *
FROM book1
WHERE price > (
								SELECT price + (price*0.4)
                                FROM book1 
                                WHERE title = 'database'
							)
		AND
    title != 'database';
    
-- 3
SELECT 
	book_1.book_id, 
    book_1.title
FROM book1 AS book_1
JOIN book1 AS book_2
ON book_1.price = book_2.price 
	AND 
   book_1.book_id != book_2.book_id
ORDER BY book_id DESC;

-- 4
SELECT 
	publisher_name, 
    publisher_id
FROM publisher
WHERE publisher_id IN (
						SELECT publisher_id 
                        FROM book1 
                        GROUP BY publisher_id 
                        HAVING count(*) >= 3
					  );
					
-- 5
SELECT 
	book1.book_id, 
    author.author_name
FROM book1
RIGHT JOIN author
ON book1.author_id = author.author_id;


-- 6
CREATE VIEW bookshop
AS
SELECT book1.book_id
FROM book1
WHERE 	book1.title LIKE '%D%' 
			AND 
		book1.price > 2000;


select * from bookshop;

-- 7
SELECT 
	book1.price, 
    book1.book_id
FROM book1
WHERE book1.book_id IN (
	SELECT book_id
	FROM book1
	ORDER BY price DESC
    LIMIT 3
)
ORDER BY price desc;

-- 8
SELECT 
	publisher.publisher_name, 
	LOWER(substr(book1.title, 1, length(book1.title) - length(book1.title)*0.5)) AS 'Half title'
from book1
join publisher
on publisher.publisher_id = book1.publisher_id;

-- 9
SELECT 
	concat(book1.title, ' - ', publisher.publisher_name) AS 'books_author'
FROM book1
JOIN publisher
ON book1.publisher_id = publisher.publisher_id
WHERE length( concat(book1.title, ' - ', publisher.publisher_name) ) > 30;

-- 10
SELECT 
	reverse(substr(reverse(book1.title), 1, 3)) AS 'last 3 character'
FROM book1;
