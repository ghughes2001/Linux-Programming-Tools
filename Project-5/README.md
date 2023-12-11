This project is very similar to Project 4, except you will use shared memory instead of a file to communicate. YOU MUST USE VERSION CONTROL. You must submit a copy of the output of the "git log."

As we will use shared memory on this project, clear out shared memory when done. If there is a mistake, use the Linux command "ipcs" to list shared memory used and see if your account name is listed. You can use the "ipcrm" command to remove a shared memory segment if it is.

For example, if you see the following doing ipcs and your user name is bnnfm:

------ Shared Memory Segments --------

key        shmid      owner      perms      bytes      nattch     status

0x0021d3a2 32379    bnnfm   777      8              0

Then, you could do ipcrm -m 32379 to remove that shared memory segment. Note that it will not remove it if you have a process that is currently attached to it. So, make sure to clear any outstanding processes that you have running.

Task:

In this project, you will write a C program that forks off a single-child process to do a task. The parent process will wait for the child to complete, and then, the parent will do some additional work.

Your program must call mathwait. c, and it will be called with a series of numbers. These numbers should all be positive. So, for example: ./mathwait 32 14 9 10 5 7 12

 Optionally, your program should also take in one option: -h: This should output a help message indicating what types of inputs it expects and what it does. Your program should terminate after receiving a -h. [Use getopt() function.]

After processing and checking for -h, before the fork, it should allocate enough shared memory for two integers.

Before creating the child, it should then set that shared memory to -200 and -200. Your program should then do a call to fork(). The parent process should then do wait() until the child process has finished.

What the child process should do:

The child process will take all the numbers from the command line arguments and put them into a dynamic array large enough for those numbers.
The child process should then find a pair of numbers that sums to 19. IT SHOULD ONLY FIND ONE PAIR; it can ignore any pair afterward. The child should then attach to a shared memory region already created by the parent.
It then checks whether the shared memory has -200 and -200 in it. If it does not, this indicates a problem with how you shared memory, so terminate with an error message (and fix your bug).
Assuming the shared memory works, it should copy the pair of these numbers to that shared memory. After that, it should detach from the shared memory and then terminate (it should not remove the shared memory, though). So, for example, if called with ./mathwait 32 14 9 10 5 7 12
It would find the pair 9,10 (or 14, 5) (or 7, 12) and write that to shared memory.
If it finds no pair that sums to 19, it should write -1 and -1 to the shared memory and then terminate.
What the parent process should do:

After forking off the child process, the parent process should do a wait call waiting for the child to end.
When the child terminates, it should check the shared memory. If it has -200 and -200 in it, then the child did not do anything to it, so some error occurred. If it has -1 and -1 in it, that means no pair was found.
If it has two different numbers in it, output those numbers as follows: Pair found by a child: 10 9