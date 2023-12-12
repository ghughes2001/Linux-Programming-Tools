This project involves writing several bash scripts that take parameters and do a task. They each require input checking and validation.
Write a script named fileChecker.sh that will do the following:

Take the name of a directory as a parameter and a string. Verify that the first parameter is a directory, output an error message, and terminate, same if more than two parameters are given. The second parameter can be anything.
Loop through all files in this directory and display their names. However, if one of the names exactly matches the second parameter, output INVALID FILE EXISTS and terminate the script.
For all the files in that directory, display only those that contain (but do not exactly match) the second input string. Do so with the following message: WARNING: Danger detected in name X, where X is replaced with the file's actual name that contained our second argument.
Display the number of files and directories present inside the given directory.


Write a script named fileInfo.sh to give users information about all arguments passed to the script. Note that it could take in any number of command line arguments. Your script should do the following for each argument:

Inform the user if the argument is a regular file, a directory, or a special file.
If it does not exist as a file or directory, generate the error and exit.
Perform each of the above operations as a function, passing the relevant argument to a function and having that particular function do the task.
Make calls to the function using a loop on the list of files specified as positional parameters.
If the user does not specify any parameter, print the “usage” line and exit with non-zero status. When I say a usage line, I mean an error message that indicates precisely the type of data the script should take in.