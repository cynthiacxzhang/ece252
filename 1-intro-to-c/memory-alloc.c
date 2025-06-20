// Memory Allocators Practice

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

// Valgrind - a tool for memory debugging, memory leak detection, and profiling
// It helps to identify memory leaks, invalid memory access, and other memory-related issues in C
// To use Valgrind, compile your C program with debugging information (using -g flag)
// and then run it with Valgrind using the command: valgrind --leak-check=full ./your_program

// Basic example of a process - not syntactically correct
int *x = malloc(sizeof(int)); // allocate memory for an integer

*x = 10;  // assign a value to the allocated memory
free(x);  // deallocate the memory
x = NULL; // set pointer to NULL to avoid dangling pointer

// memory allocators: malloc, calloc, realloc, free
// malloc: allocates memory without initializing it
// calloc: allocates memory and initializes it to zero
// realloc: resizes previously allocated memory
// free: deallocates previously allocated memory

int main()
{
    // Example of using malloc
    int *arr = malloc(5 * sizeof(int)); // allocate memory for an array of 5 integers
    if (arr == NULL)
    {
        perror("Failed to allocate memory");
        return EXIT_FAILURE; // exit if memory allocation fails
    }

    // Initialize the allocated memory
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i + 1; // assign values to the array
    }

    // Print the values
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);  // deallocate the memory
    arr = NULL; // set pointer to NULL to avoid dangling pointer

    // Example of using calloc
    int *arr_calloc = calloc(5, sizeof(int)); // allocate and initialize memory for an array of 5 integers
    if (arr_calloc == NULL)
    {
        perror("Failed to allocate memory");
        return EXIT_FAILURE; // exit if memory allocation fails
    }

    // Print the values (should be all zeros)
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr_calloc[i]);
    }
    printf("\n");

    free(arr_calloc);  // deallocate the memory
    arr_calloc = NULL; // set pointer to NULL to avoid dangling pointer

    return EXIT_SUCCESS;
}
