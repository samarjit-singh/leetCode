# Write your MySQL query statement below
# Select tweet_id from Tweets WHERE LEN(content) > 15;
SELECT tweet_id FROM Tweets WHERE LENGTH(content) > 15;
