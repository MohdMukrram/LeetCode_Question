# Write your MySQL query statement below
WITH unique_activity AS (
    SELECT DISTINCT
        user_id,
        activity_date
    FROM Activity
    WHERE activity_date BETWEEN '2019-06-28' AND '2019-07-27'
),
ranked AS (
    SELECT
        user_id,
        activity_date,
        COUNT(*) OVER (
            PARTITION BY activity_date
        ) AS active_users
    FROM unique_activity
)
SELECT DISTINCT
    activity_date AS day,
    active_users
FROM ranked;