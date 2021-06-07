#!/bin/bash

set -e

rm -f imdb.sqlite3

sqlite3 imdb.sqlite3 < schema.sql
sqlite3 imdb.sqlite3 <<EOS
.mode csv
.separator "|"
.import ./small-dataset/names.csv        names
.import ./small-dataset/titles.csv       titles
.import ./small-dataset/title_akas.csv   title_akas
.import ./small-dataset/crews.csv        crews
.import ./small-dataset/episodes.csv     episodes
.import ./small-dataset/principals.csv   principals
.import ./small-dataset/ratings.csv      ratings
EOS
