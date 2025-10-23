-- Write your PostgreSQL query statement below
-- product_id, units, price
WITH temp AS(
    SELECT 
        p.product_id,
        p.start_date,
        p.end_date,
        p.price,
        SUM(u.units) units
    FROM Prices p
    LEFT JOIN UnitsSold u ON p.product_id = u.product_id AND 
        u.purchase_date BETWEEN p.start_date AND p.end_date
    GROUP BY 
        p.product_id, p.start_date, p.end_date, p.price
)
SELECT 
    product_id,
    COALESCE(ROUND(SUM(units * price)/SUM(units), 2), 0) average_price
FROM temp
GROUP BY product_id ;