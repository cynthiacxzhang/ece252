#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define bufsize 1000

const int MAX_SIZE = 100;

bool isValidInput(const char *input)
{
    // Check if the input is not NULL and not empty
    return (input != NULL && strlen(input) > 0);
}

int main()
{
    // Example usage of boolean type
    bool isValid = isValidInput("Hello");

    if (isValid)
    {
        printf("Valid input.\n");
    }
    else
    {
        printf("Invalid input.\n");
    }

    return 0;
}