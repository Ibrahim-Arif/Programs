DROP DATABASE IF EXISTS ig_clone;
CREATE DATABASE ig_clone;
USE ig_clone; 

create table logs (
	username 	varchar(255) 	NOT NULL,
    logged_at 	TIMESTAMP 		DEFAULT NOW()
);

CREATE TABLE users (
    id 			INTEGER 		AUTO_INCREMENT PRIMARY KEY,
    username 	VARCHAR(255) 	UNIQUE NOT NULL,
    created_at 	TIMESTAMP 		DEFAULT NOW()
);

CREATE TABLE photos (
    id 			INTEGER 		AUTO_INCREMENT PRIMARY KEY,
    image_url 	VARCHAR(255) 	NOT NULL,
    user_id 	INTEGER 		NOT NULL,
    created_at 	TIMESTAMP 		DEFAULT NOW(),
    
    FOREIGN KEY(user_id) REFERENCES users(id)
);

CREATE TABLE comments (
    id 				INTEGER 		AUTO_INCREMENT PRIMARY KEY,
    comment_text 	VARCHAR(255) 	NOT NULL,
    photo_id 		INTEGER 		NOT NULL,
    user_id 		INTEGER 		NOT NULL,
    created_at 		TIMESTAMP 		DEFAULT NOW(),
    
    FOREIGN KEY(photo_id) REFERENCES photos(id),
    FOREIGN KEY(user_id) REFERENCES users(id)
);

CREATE TABLE likes (
    user_id 		INTEGER 		NOT NULL,
    photo_id 		INTEGER 		NOT NULL,
    created_at 		TIMESTAMP 		DEFAULT NOW(),
    
    FOREIGN KEY(user_id) REFERENCES users(id),
    FOREIGN KEY(photo_id) REFERENCES photos(id),
    PRIMARY KEY(user_id, photo_id)
);

CREATE TABLE follows (
    follower_id 	INTEGER 	NOT NULL,
    followee_id 	INTEGER 	NOT NULL,
    created_at 		TIMESTAMP 	DEFAULT NOW(),
    
    FOREIGN KEY(follower_id) REFERENCES users(id),
    FOREIGN KEY(followee_id) REFERENCES users(id),
    PRIMARY KEY(follower_id, followee_id)
);

CREATE TABLE tags (
  id 			INTEGER 		AUTO_INCREMENT PRIMARY KEY,
  tag_name 		VARCHAR(255) 	UNIQUE,
  created_at 	TIMESTAMP 		DEFAULT NOW()
);

CREATE TABLE photo_tags (
    photo_id 	INTEGER 		NOT NULL,
    tag_id 		INTEGER 		NOT NULL,
    
    FOREIGN KEY(photo_id) REFERENCES photos(id),
    FOREIGN KEY(tag_id) REFERENCES tags(id),
    PRIMARY KEY(photo_id, tag_id)
);


SELECT username, created_at
FROM users
ORDER BY created_at
LIMIT 5;

SELECT username
FROM users
LEFT JOIN photos
ON users.id = photos.user_id
WHERE photos.image_url IS NULL;

SELECT photo_id, count(user_id)
FROM users
JOIN likes
GROUP BY user_id;

SELECT users.username, photos.image_url, count(*)
FROM users
JOIN photos
	ON photos.user_id = users.id
JOIN likes
	ON likes.photo_id = photos.id
GROUP BY photos.id
ORDER BY count(*) DESC
LIMIT 1;

SELECT
	(SELECT count(*) from photos) 	/ 	( (SELECT count(*) from users) 		#total photos / (total users - non poster users)
										 - (SELECT count(*)
											FROM users
											LEFT JOIN photos
											ON users.id = photos.user_id
											WHERE photos.image_url IS NULL) )
	AS 'AVG'
;

SELECT 
	tags.tag_name, 
    count(*) AS total
FROM photo_tags
JOIN tags
ON tags.id = photo_tags.tag_id
GROUP BY tag_id
ORDER BY total DESC
LIMIT 5;

SELECT 
	username, 
    count(*) AS total_liked
FROM users
JOIN likes
	ON users.id = likes.user_id
GROUP BY users.id	
HAVING total_liked = (SELECT count(*) FROM photos);

select username, photos.id, count(*) AS likes, datediff(now(), photos.created_at) AS created_at
from users
join photos
on users.id = photos.user_id
join likes
on photos.id = likes.photo_id
group by photos.id
having username = 'Kenton_Kirlin';


select username, follower_id, count(*) AS likes
from users
join follows
on users.id = follows.followee_id
join likes
on likes.photo_id = (
	select photos.id 
	from photos 
	where photos.user_id = follows.follower_id 
	order by photos.created_at desc limit 1
)
where users.username = 'Kenton_Kirlin'
group by follower_id;


-- NEWS FEED QUERY ----
CREATE VIEW newsfeed
AS
SELECT follows.follower_id,
		( SELECT username 
		  FROM users 
          WHERE follows.follower_id = users.id
		) 										AS follower, 
        photos.id 								AS photo_id,
        photos.image_url 						AS URL,
        ( SELECT count(*)
		  FROM likes
          WHERE likes.photo_id = photos.id
		) 										AS likes,
        ( SELECT 1
			from likes
            where likes.user_id = users.id 
					AND 
				  photos.id = photo_id
        ) 										AS is_liked,
		( SELECT count(*)
		  FROM comments
          WHERE comments.photo_id = photos.id
		) 										AS Comments_count,
        (
		  SELECT comments.user_id
          FROM comments
          WHERE comments.photo_id = photos.id
          ORDER BY comments.created_at DESC
          LIMIT 1
        ) 										AS commenter_id,
        (
		  select username
          from users
          where users.id = commenter_id
        )										AS commenter_name,
        (
		  SELECT comments.comment_text
          FROM comments
          WHERE photos.id = comments.photo_id 
				AND 
                commenter_id = comments.user_id
		  ORDER BY comments.created_at DESC
		  LIMIT 1
        )										AS comment_text,
        datediff(now(), photos.created_at) 		AS photo_created_at
        
FROM users
JOIN follows
ON users.id = follows.followee_id
JOIN photos
ON photos.id = (
	SELECT photos.id
    FROM photos
    WHERE photos.user_id = follows.follower_id
    ORDER BY photos.created_at DESC
    LIMIT 1
)
WHERE users.username = 'Arely_Bogan63'
GROUP BY follower_id;

-- users profile query..
CREATE VIEW users_profile
AS 
select
	username								AS username,
	photos.id								AS photo_id,
	( 
	SELECT count(*)
	FROM likes
	WHERE likes.photo_id = photos.id
	) 										AS likes,
	(
	select count(*)
	from comments
	where comments.photo_id = photos.id
	)										AS comments,
	datediff(now(), photos.created_at)		AS created_at
from users
join photos
on users.id = photos.user_id
group by photos.id
having username = 'Tabitha_Schamberger11';

-- profile details
CREATE VIEW profile_detail
AS
select username, 
	(
		SELECT count(*)
		FROM photos
		where photos.user_id = users.id
	) 											AS posts,
	( 
		SELECT count(*)
		FROM follows
		WHERE follows.followee_id = users.id
	)		 									AS followers,
	( 
		SELECT count(*)
		FROM follows
		WHERE follows.follower_id = users.id
	) 											AS followings
from users
where username = 'Tabitha_Schamberger11';

-- image detail
CREATE VIEW image_detail
AS
SELECT
	( 
		SELECT count(*)
		FROM likes
		WHERE likes.photo_id = photos.id
	) 										AS likes,
datediff(now(), photos.created_at)		AS created_at
FROM photos
WHERE photos.id = 4;