/*
DROP TABLE states.state_details;
DROP TABLE states.states_official_languages;
DROP TABLE states.language;
DROP TABLE states.type_government;
DROP TABLE states.state;

DROP SCHEMA states;
*/

CREATE SCHEMA states;

CREATE TABLE states.state (
    id integer PRIMARY KEY,
    name varchar(50) UNIQUE NOT NULL,
    capital_city varchar(50) UNIQUE NOT NULL,
    EU boolean NOT NULL,
    NATO boolean NOT NULL
);

CREATE TABLE states.type_government (
    id integer PRIMARY KEY,
    name varchar(200) UNIQUE NOT NULL,
    head_of_state varchar(100),
    head_of_government varchar(100)
);

CREATE TABLE states.state_details (
    state_id integer PRIMARY KEY REFERENCES states.state(id) ON DELETE CASCADE,
    population integer,
    head_of_state varchar(200),
    head_of_government varchar(200),
    type_government_id integer REFERENCES states.type_government(id)
);

CREATE TABLE states.language (
    id integer PRIMARY KEY,
    name varchar(50) UNIQUE NOT NULL,
    total_number_speakers integer
);

CREATE TABLE states.states_official_languages (
    state_id integer REFERENCES states.state(id) ON DELETE CASCADE,
    language_id integer REFERENCES states.language(id) ON DELETE CASCADE
);

COPY states.state FROM 'C:\\Users\\Public\\Documents\\States1.csv' DELIMITER ',' CSV HEADER;
COPY states.type_government FROM 'C:\\Users\\Public\\Documents\\States3.csv' DELIMITER ',' CSV HEADER;
COPY states.state_details FROM 'C:\\Users\\Public\\Documents\\States2.csv' DELIMITER ',' CSV HEADER;
COPY states.language FROM 'C:\\Users\\Public\\Documents\\States4.csv' DELIMITER ',' CSV HEADER;
COPY states.states_official_languages FROM 'C:\\Users\\Public\\Documents\\States5.csv' DELIMITER ',' CSV HEADER;

-- DROP USER viewer;
CREATE USER viewer WITH PASSWORD 'myPassword';
GRANT USAGE ON SCHEMA states TO viewer;
GRANT SELECT ON ALL TABLES IN SCHEMA states TO viewer;
ALTER DEFAULT PRIVILEGES FOR USER viewer IN SCHEMA states
GRANT SELECT ON TABLES TO viewer;
SET ROLE viewer; -- Mimicking the role of viewer as the superuser

SELECT COUNT(*) AS Number_of_European_states FROM states.state;

SELECT SUM(population) AS total_population_in_Europe FROM states.state_details;

SELECT name AS states_in_EU_not_in_NATO FROM states.state
WHERE EU = TRUE AND NATO = FALSE;

SELECT name AS states_in_NATO_not_in_EU FROM states.state
WHERE NATO = TRUE AND EU = FALSE;

SELECT state.name AS states_with_monarchy FROM states.state, states.state_details, states.type_government
WHERE state.id = state_details.state_id
AND state_details.type_government_id = type_government.id
AND type_government.id IN (2, 5, 6, 10);

SELECT MIN(language.name) AS most_popular_official_language, COUNT(*) AS number_of_states_in_which_it_is_official
FROM states.language, states.states_official_languages
WHERE language.id = states_official_languages.language_id
GROUP BY states_official_languages.language_id
ORDER BY COUNT(*) DESC
LIMIT 1;
