-- Write your PostgreSQL query statement below
WITH tmp AS(
    SELECT 
        id,
        country,
        state,
        amount,
        trans_date,
        TO_CHAR(trans_date, 'YYYY-MM') AS month,
        (CASE WHEN state = 'approved' THEN amount ELSE 0 END) approved_amount
    FROM
    Transactions
)
SELECT 
    month,
    country,
    COUNT(*) trans_count,
    SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) approved_count,
    SUM(amount) trans_total_amount,
    SUM(approved_amount) approved_total_amount
FROM tmp
GROUP BY 
    month,
    country ;