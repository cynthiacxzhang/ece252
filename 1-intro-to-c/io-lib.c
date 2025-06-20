// Input/Output Library

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h> // For POSIX compliant systems, provides access to the POSIX operating system API

printf("hello world\n"); // Print a message to the console

printf("%s is %d years old\n", "Alice", 30); // Print a formatted string with a string and an integer

// Return codes
int main()
{
    // Return codes are used to indicate the success or failure of a program
    // 0 typically indicates success, while non-zero values indicate different types of errors
    return 0; // Return success status
}

// typically returns 0 for success, -1 for failure, and errno for specific error codes
// errno is a global variable that is set by system calls and some library functions in the event
