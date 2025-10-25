-- Write your PostgreSQL query statement below
SELECT 
    p.project_id,
    ROUND(AVG(e.experience_years), 2) average_years
FROM 
    Project p
INNER JOIN Employee e USING(employee_id)
GROUP BY p.project_id ;