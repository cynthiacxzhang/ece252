#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/*
Program:
- linear array of integers: want to perform linear search with three processes
- e.g. splitting the work between one parent and two children
- parent process will fork two child processes
- each child will search a portion of the array for a target value
- each child will return the index of the target value if found, or -1 if not
- parent will wait for both children to finish and then print the results
*/

#define ARRAY_SIZE 100
#define TARGET_VALUE 42

int array[ARRAY_SIZE]; // global array to be searched
int array_len = ARRAY_SIZE;
int search_value = TARGET_VALUE;

// Note: no need for pipes since the processes don't need to communicate
// - because the child processes inherit the fds of the parent, they all share the same console output interface

pid_t pid;
