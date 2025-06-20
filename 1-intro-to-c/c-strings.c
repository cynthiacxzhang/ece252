// C Strings

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// C strings are arrays of characters that end with a null character ('\0').
// e.g. null-terminated strings.

char str1[] = "Hello, World!"; // Implicitly null-terminated
// allocates enough space for the string and the null terminator that follows it.

char str2[20] = "Hello, World!"; // Explicitly sized array, allocates space for 20 characters
char str3[20];                   // Uninitialized array, can be filled later

// which one of the top three are cstrings?
// str1 is a C string because it is initialized with a string literal, which is null-terminated.
// str2 is also a C string because it is initialized with a string literal and has enough space for the string and the null terminator.
// str3 is not a C string until it is filled with characters and a null terminator is added.