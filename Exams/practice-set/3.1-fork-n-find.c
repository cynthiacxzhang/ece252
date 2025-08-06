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

int main()
{

    pid = fork(); // creating first child process

    // error check
    if (pid == -1)
    {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0)
    { // first child process
        // search first half of the array
        for (int i = 0; i < array_len / 2; i++)
        {
            if (array[i] == search_value)
            {
                printf("Child 1 found value at index: %d\n", i);
                exit(i); // exit with index if found
            }
        }
        return -1; // return -1 if not found
    }
    else
    {                        // parent process
        pid_t pid2 = fork(); // creating second child process

        // error check
        if (pid2 == -1)
        {
            printf("Fork failed\n");
            return 1;
        }
        else if (pid2 == 0)
        { // second child process
            // search second half of the array
            for (int i = array_len / 2; i < array_len; i++)
            {
                if (array[i] == search_value)
                {
                    printf("Child 2 found value at index: %d\n", i);
                    exit(i); // exit with index if found
                }
            }
            return -1; // return -1 if not found
        }
        else
        { // parent process - searches latter third of array
            for (int i = 0; i < array_len; i++)
            {
                if (array[i] == search_value)
                {
                    printf("Parent found value at index: %d\n", i);
                    exit(i); // exit with index if found
                }
            }
            return -1; // return -1 if not found
        }
    }
}