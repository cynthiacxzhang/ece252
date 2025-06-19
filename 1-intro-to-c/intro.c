// Basic C Programming Practice

/*
Includes are directives that tell the compiler to include the contents of a file in the program.
*/

#include <stdio.h>  // standard input/output library
#include <stdlib.h> // standard library for memory allocation, process control, etc.
#include <string.h> // string handling functions
#include <errno.h>  // error number definitions

/*
DEFINE is a preprocessor directive that defines a macro.
MACRO is a fragment of code that has been given a name. Whenever the name
is used, it is replaced by the code fragment.

For example: #define SQUARE(x) ((x) * (x))
*/

#define bufsize 1000 // Define a buffer size for input

/*
A buffer is a temporary storage area in memory used to hold data
while it is being transferred between two locations, such as between
a program and an input/output device.
*/

// STRUCTS INTRO
struct MyStruct
{
    char character[50];
    int number;
};

typedef struct MyStruct NewStructName; // Typedef for easier reference

int main()
{

    // to call the struct we just created
    // this is how we can create an instance of the struct MyStruct
    NewStructName myStructInstance;

    // to call members of the struct
    strcpy(myStructInstance.character, "Hello, World!"); // Copy string into character array

    /*The strcpy() function in C is a standard library function used to copy a null-terminated
    string from a source location to a destination location. It is declared in the <string.h>
    header file.*/

    myStructInstance.number = 42; // Assign an integer value

    // printing the values of the struct members
    printf("Character: %s\n", myStructInstance.character); // %s is ua format specifier for strings
    printf("Number: %d\n", myStructInstance.number);       // %d is a format specifier for integers
}