#include "apue.h"

#define BUFSIZE 4096

// Unbuffered I/O example
// This program reads data from standard input and writes it to standard output
int main(void)
{
    int n;                                             // number of bytes read
    char buf[BUFSIZE];                                 // buffer to hold data
    while ((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0) // read data from standard input
    {
        if (write(STDOUT_FILENO, buf, n) != n) // write data to standard output
        {
            err_sys("write error");

            if (n < 0)
            { // check for read error
                err_sys("read error");
            }
        }
        exit(0); // exit the program successfully
    }