// Continued struct study

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define bufsize 1000 // Define a buffer size for input

// Define a struct to hold student information
typedef struct
{
    char a;
    int b;
} student_t; // Typedef for easier reference, _t is a common convention for typedefs

int main()
{
    // Create an instance of the student struct
    student_t student;

    student_t y = {0, 1};   // Initialize an instance of the struct with values, 0 for 'a' and 1 for 'b'
    student_t z = {.b = 1}; // Designated initializer for clarity, other members are initialized to 0

    return 0; // Return success status
}