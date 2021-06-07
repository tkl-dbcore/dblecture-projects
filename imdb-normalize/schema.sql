
CREATE TABLE names (
  id varchar(10) NOT NULL,
  name varchar(100) NOT NULL,
  birth_year int,
  death_year int,
  profession varchar(100) NOT NULL,
  known_for_titles varchar(100),
  PRIMARY KEY (id)
);

CREATE TABLE titles (
  id varchar(10) NOT NULL,
  type varchar(100) NOT NULL,
  title varchar(100) NOT NULL,
  original_title varchar(100) NOT NULL,
  is_adult int NOT NULL,
  start_year int,
  end_year int,
  minutes int,
  genres varchar(100),
  PRIMARY KEY(id)
);

CREATE TABLE title_akas (
  title_id varchar(10) NOT NULL,
  ordering int NOT NULL,
  local_title varchar(100) NOT NULL,
  region varchar(100),
  language varchar(100),
  types varchar(100),
  attributes varchar(100),
  is_original int,
  PRIMARY KEY(title_id, ordering)
);

CREATE TABLE crews (
  title_id varchar(10) NOT NULL,
  directors varchar(100),
  writers varchar(100),
  PRIMARY KEY(title_id)
);

CREATE TABLE episodes (
  id varchar(10) NOT NULL,
  title_id varchar(10) NOT NULL,
  season_number int,
  episode_number int,
  PRIMARY KEY(id)
);

CREATE TABLE principals (
  title_id varchar(10) NOT NULL,
  ordering int NOT NULL,
  name_id varchar(10) NOT NULL,
  category varchar(100) NOT NULL,
  job varchar(100),
  characters varchar(100),
  PRIMARY KEY(title_id, ordering)
);

CREATE TABLE ratings (
  title_id varchar(10) NOT NULL,
  rating numeric NOT NULL,
  num_votes int NOT NULL,
  PRIMARY KEY(title_id)
);
