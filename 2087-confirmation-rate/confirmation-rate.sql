-- Write your PostgreSQL query statement below
SELECT 
    s.user_id,
    ROUND(SUM(CASE WHEN c.action = 'confirmed' THEN 1 ELSE 0 END)/COUNT(*)::numeric, 2) AS confirmation_rate
FROM
    Signups s
LEFT JOIN Confirmations c USING(user_id)
GROUP BY s.user_id;
