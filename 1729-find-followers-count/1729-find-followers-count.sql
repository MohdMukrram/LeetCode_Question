WITH follower_count AS (
    SELECT
        user_id,
        COUNT(*) AS followers_count
    FROM Followers
    GROUP BY user_id
)
SELECT
    user_id,
    followers_count
FROM follower_count
ORDER BY user_id;