-- Write your PostgreSQL query statement below
SELECT 
    v.customer_id,
    COUNT(v.visit_id) count_no_trans
FROM
    Visits v
LEFT JOIN Transactions t USING(visit_id)
WHERE transaction_id IS NULL 
GROUP BY customer_id;

