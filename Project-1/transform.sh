#!/bin/bash
#Author: Grant Hughes
#Purpose: Practice writing with advanced commands using csv file


cat $1 >> file1.csv
sed -i '1i First Last Phone-Number Expense1 Expense2 Expense3' file1.csv
mv file1.csv move1.txt

touch move2.txt
cp move1.txt move2.txt
sed -i 's/Lisa/Lee/g' move2.txt

touch move3.txt
grep -i '(999)' move2.txt >> file2.txt
awk '{print $1, $2}' file2.txt >> move3.txt

touch move4.txt
awk '{print $2, $1}' move1.txt >> file4.txt
grep '^M' file4.txt >> Last-First.txt && grep '^N' file4.txt >> Last-First.txt
awk '{print $2}' Last-First.txt >> move4.txt

touch file5.txt
grep '$[4-9][0-9].[0-9][0-9]' move1.txt >> file5.txt
awk '{print $1, $2, $3}' file5.txt >> unsorted5.txt
sort -k3 unsorted5.txt -o move5.txt
