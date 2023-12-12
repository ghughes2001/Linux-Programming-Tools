#!/bin/bash

#gives users information about all arguments passed
#Inform the user if the argument is a regular file, a directory, or a special file.
#If it does not exist as a file or directory, generate the error and exit.
#Perform each of the above operations as a function, passing the relevant argument to a function and having that particular function do the task.
#Make calls to the function using a loop on the list of files specified as positional parameters.
#If the user does not specify any parameter, print the “usage” line and exit with non-zero status. When I say a usage line, I mean an error message that indicates precisely the type of data the script should take in.


if [ "$#" -eq 0 ]
then
  echo "No arguments of files or directories supplied"
  exit 1
fi

function fileType() {
        for args
        do
                if [[ -d $args ]] ; then
                        echo "$args is a directory"
                elif [[ -f $args ]] ; then
                        echo "$args is a file"
                elif [[ -e $args ]] ; then
                        echo "$args is a special file"
                else
                        echo "Error: $args does not exist as a file or directory"
                        exit
                fi
        done
}

for arguments in "$@"
do
        fileType $arguments
done
