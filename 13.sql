SELECT DISTINCT name FROM people
JOIN stars ON people.id = person_id
JOIN movies ON movie_id = movies.id
WHERE movies.id IN
    (SELECT movie_id FROM movies
     JOIN people ON stars.person_id = people.id
     JOIN stars ON stars.movie_id = movies.id
     WHERE people.name = "Kevin Bacon"
     AND birth = 1958)
AND name IS NOT "Kevin Bacon";