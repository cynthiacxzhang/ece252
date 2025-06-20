// Void Pointers in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

// A void pointer is a special type of pointer that can point to any data type.
// It is declared using the keyword `void` and can be used to create generic functions or
// data structures that can handle different types of data without knowing their specific types at compile time.

void printValue(void *ptr, char type)
{
    // Check the type of data pointed to by the void pointer and print accordingly
    switch (type)
    {
    case 'i': // Integer
        printf("Integer value: %d\n", *(int *)ptr);
        break;
    case 'f': // Float
        printf("Float value: %.2f\n", *(float *)ptr);
        break;
    case 'c': // Character
        printf("Character value: %c\n", *(char *)ptr);
        break;
    case 's': // String
        printf("String value: %s\n", (char *)ptr);
        break;
    default:
        printf("Unknown type\n");
    }
}