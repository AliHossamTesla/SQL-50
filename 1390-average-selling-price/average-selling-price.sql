-- -- Write your PostgreSQL query statement below
-- -- product_id, units, price
-- WITH temp AS(
--     SELECT 
--         p.product_id,
--         p.start_date,
--         p.end_date,
--         p.price,
--         SUM(u.units) units
--     FROM Prices p
--     LEFT JOIN UnitsSold u ON p.product_id = u.product_id AND 
--         u.purchase_date BETWEEN p.start_date AND p.end_date
--     GROUP BY 
--         p.product_id, p.start_date, p.end_date, p.price
-- )
-- SELECT 
--     product_id,
--     COALESCE(ROUND(SUM(units * price)/SUM(units), 2), 0) average_price
-- FROM temp
-- GROUP BY product_id ;
-- Calculate average selling price per product
WITH price_units AS (
    SELECT 
        p.product_id,
        p.price,
        COALESCE(SUM(u.units), 0) AS total_units
    FROM Prices p
    LEFT JOIN UnitsSold u 
        ON p.product_id = u.product_id
        AND u.purchase_date BETWEEN p.start_date AND p.end_date
    GROUP BY p.product_id, p.price
)
SELECT 
    product_id,
    ROUND(
        CASE 
            WHEN SUM(total_units) = 0 THEN 0
            ELSE SUM(total_units * price)::numeric / SUM(total_units)
        END, 
        2
    ) AS average_price
FROM price_units
GROUP BY product_id
ORDER BY product_id;
