:: WARNINGS:
:: These commands are for Windows only.
:: You need Node.js and G++ tools to run them.
:: They should be run in the 'codes' directory.
:: Remember to replace the string in brackets.
:: Drag the CSV file here before running.
:: Note that the CSV file will be DELETED after running!

:: COMMAND FORMAT:
:: commands.bat [CONTEST_NAME] [CSV_FILENAME] [SPECIAL_RULES_"YES"/"NO"]

g++ 2_convert_csv_files.cpp -o 2_convert_csv_files
g++ 3_calculate_performances.cpp -o 3_calculate_performances
g++ 4_update_ratings_and_reports.cpp -o 4_update_ratings_and_reports
g++ 5_roll_ranks_and_leaderboards.cpp -o 5_roll_ranks_and_leaderboards
node 1_fetch_usernames.js
2_convert_csv_files %1 %2
3_calculate_performances %3
4_update_ratings_and_reports
5_roll_ranks_and_leaderboards
del *.txt
del *.exe
del %2
pause