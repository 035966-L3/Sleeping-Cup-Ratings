#!/bin/bash

# WARNINGS:
# These commands are for Linux only.
# You need Node.js and G++ tools to run them.
# They should be run in the 'codes' directory.
# Remember to replace the string in brackets.
# Drag the CSV file here before running.
# Note that the CSV file will be DELETED after running!

# COMMAND FORMAT:
# chmod +x commands.sh
# ./commands.sh [CONTEST_NAME] [CSV_FILENAME] [SPECIAL_RULES_"YES"/"NO"]

g++ 1_convert_csv_files.cpp -o 1_convert_csv_files
g++ 2_calculate_performances.cpp -o 2_calculate_performances
g++ 3_update_ratings_and_reports.cpp -o 3_update_ratings_and_reports
g++ 4_roll_ranks_and_leaderboards.cpp -o 4_roll_ranks_and_leaderboards
node ../fetch_usernames.mjs
./1_convert_csv_files "$1" "$2"
./2_calculate_performances "$3"
./3_update_ratings_and_reports
./4_roll_ranks_and_leaderboards
rm -f *.txt
rm -f 1_convert_csv_files
rm -f 2_calculate_performances
rm -f 3_update_ratings_and_reports
rm -f 4_roll_ranks_and_leaderboards
rm -f "$2"
read -p "Press Enter to continue..."
