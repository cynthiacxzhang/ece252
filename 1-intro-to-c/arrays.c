// Arrays

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define memset memset // Define a macro for memset to avoid confusion with the standard library function
#define memcpy memcpy // Define a macro for memcpy to avoid confusion with the standard library function

int arr[5] = {1, 2, 3, 4, 5}; // Declare and initialize an array of ints, constant length of 5
int arr2[] = {1, 2, 3, 4, 5}; // Array of ints, constant length of 5, no size specified

const int n = 5; // Define a variable for the size of the array
int arr3[n];     // Variable length array, n must be defined before this line

// Dynamic array allocation
int *arr4 = malloc(n * sizeof(int)); // Allocate memory for an array of n integers

memset(arr4, 0, n * sizeof(int)); // Initialize the allocated memory to zero
                                  // ➤ Sets num bytes of memory starting from ptr to value.

memcpy(arr4, arr, sizeof(int) * n); // Copy the contents of arr to arr4
                                    // ➤ Copies num bytes from src to dest.