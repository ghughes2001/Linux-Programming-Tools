In this project, you will write a C program that forks off a single-child process to do a task. The parent process will wait for it to complete, and then some additional work will be done.

Your program should be called mathWork.c, and it will be called with a filename followed by a series of numbers. So, for example, ./mathWork number.txt 11 9 123 13 0 -9

Optionally, your program should also take in one option: 

-h: This should output a help message indicating what types of inputs it expects and what it does. Your program should terminate after receiving a -h.

After processing and checking for -h, your program should call to fork(). The parent process should then wait() until the child process has finished.

What the child process should do:

The child process will take all the numbers from the command line arguments and put them into a dynamic array large enough size for those numbers.
Once this is done, you should then open the file you were given for writing and then write all the numbers to the file. However, whenever the child writes to the file, it should write it in the following format: Child: PID: Data
For example, if the PID of our child process is 2817, we would write to the file:
           Child: 2817: 11 9 123 13 0 -9

You should then process this array to find the prime numbers. You have to store all the prime numbers in a dynamic array. Your program should then output any pairs of prime numbers that sum is less than 50 in the file, so in the file, you would output like this:
           Child: 2817: Pair: 2-3; 11-3; 19-5;

Note that the pairs can be in any order as long as you list all the possible pairs. Once complete, the child process should close the file, free the dynamic array, and terminate.
It should give EXIT_SUCCESS if it found at least one pair that summed is less than 50 and an EXIT_FAILURE if it found none.
What the parent process should do:

After forking off the child process, the parent process should do a wait call waiting for the child to end. 
It should then check the status code returned from the child process and write that to the file. 
For example, assuming its process ID was 2817 and it got EXIT_SUCCESS: Parent: 2817: EXIT_SUCCESS