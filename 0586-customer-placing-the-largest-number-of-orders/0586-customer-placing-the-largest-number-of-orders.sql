WITH customer_count AS (
    SELECT
        customer_number,
        COUNT(*) AS large_cust
    FROM Orders
    GROUP BY customer_number
),
ranked AS (
    SELECT
        customer_number,
        large_cust,
        ROW_NUMBER() OVER (
            ORDER BY large_cust DESC
        ) AS rnk
    FROM customer_count
)
SELECT customer_number
FROM ranked
WHERE rnk = 1;