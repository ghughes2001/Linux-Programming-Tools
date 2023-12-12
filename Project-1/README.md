At the beginning of each program (Bash script file), after the “#!/bin/bash” line, there should be comments with the author’s name and the purpose of the script. If you don't include this information, up to 2 points will be subtracted from your score for each part of the project.
[7 points] Write a Bash shell script named info.sh. The output of this script must contain the following information:
          1. The name of your script;
          2. The name of the current working directory;
          3. The name of UNIX machine;
          4. The name of the login shell;
          5. Total number of parameters of the script;
          6. Current number of users on the system (could require a pipe)
          7. Current time (YY/MM/DD HH-MM-SS)
[3 points] A screenshot of you running the script on delmar with the complete output of the script. All output screenshots are necessary. Make a single PDF file for this part containing all screenshots. 
Note that I want your script to give this information through the use of commands, not simply use the echo command to output what you think it is. It is fine to use echo with other commands. So, for example, if you want to know the location of your home directory, it is fine to do:
                             echo $HOME, but not to do echo /home/bnnfm.
=============================================================================================
                                                                        Part #2 [30 Points]
==============================================================================================
[2 points] At the beginning of each program (Bash script file), after the “#!/bin/bash” line, there should be comments with the author’s name and the purpose of the script. If you don't include this information, up to 2 points will be subtracted from your score for each part of the project.
Write a Bash shell script named transform.sh. This script will be working with a data file named as the first argument to your script, so you would run it with the command:
                    ./transform.sh fileNmae.csv
The data files your script will work with will contain lines in the following format:
                  David Lee |(444)444-5678|$15.00|$55.00|$30.25
                  Lisa Smith|(999)999-1234|$22.00|$70.00|$17.75
                  Kevin Johnson|(777)777-7777|$7.00|$80.00|$22.00
                   Rachel Miller|(111)222-3333|$14.00|$90.00|$27.50
which indicates the amount someone expenses in three different categories: Expense1, Expense2, and Expense3.
Note that the actual file will contain other names, phone numbers, and amounts. You can assume that any names will have only a first and last name, with only alphabetic characters. I want your script to do the following tasks and save the resulting data in the locations asked.
1) Output the data to a new file, add a header to it, and send that data to a file called move1.txt.
                           This head should be as follows: Name Phone Number Expense1 Expense2 Expense3
2) Duplicate the file in a file called move2.txt, except replace any names of "Lisa" with "Lee"
3) Put the list of persons (only their names, no other data) with area code 999 in a file called move3.txt
4) Anyone whose last names start with an M or N should go into a file called move4.txt, but only their first names.
5) Find the people who spend at least $40.00 in any category in the file move5.txt. I just want their full name and phone number, nothing else for this. This data should be sorted by their last name.
5 points for each task finished. Note that you can do each of these tasks in more than one command if you like, but the end result should be the files move1.txt - move5.txt
Note: These tasks do not have to be done in one single command. They can be done in a series of commands working on different files or piped from one command to another. In fact, I would suggest breaking the tasks up if that would make some of them easier.
 
[3 points] A screenshot of you running the script on delmar with the complete output of the script. All output screenshots are necessary. Make a single PDF file for this part containing all screenshots. 