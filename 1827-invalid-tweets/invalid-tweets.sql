-- Write your PostgreSQL query statement below
SElECT 
    tweet_id
FROM
    Tweets
WHERE 
    LENGTH(content) > 15 ;