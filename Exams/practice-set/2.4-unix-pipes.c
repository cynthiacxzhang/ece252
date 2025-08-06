#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 100
#define PRINT_FILE "print.txt"

// Program:
// - one process will spawn another
// - child process will read data from a file and send it to the parent process through a pipe
// - child will need to read data from file into a buffer, then write that buffer into the pipe
// - parent process will send it to a print (assume predefined function)
// - parent will read data from the pipe into a buffer, then call print function to print the buffer contents

void print(const char *buffer)
{
    printf("Data: %s\n", buffer);
}

int fds[2]; // file descriptors for the pipe
pid_t pid;  // process identifier

int main(void)
{

    // create the pipe
    pipe(fds);

    // fork the process from the PID of the parent after the pipe is created
    pid = fork();

    if (pid == -1)
    {
        printf("Fork failed\n");
        return 1;
    }

    // if parent process
    if (pid > 0)
    {
        // close the write end of the pipe
        close(fds[1]);

        // read from the pipe into a buffer
        char buffer[BUFFER_SIZE];
        int n = read(fds[0], buffer, BUFFER_SIZE); // n is the number of bytes read, not the content

        // call the print function
        print(buffer);
    }
    // if child process
    else
    {
        // close the read end of the pipe
        close(fds[0]);

        int filefd = open(PRINT_FILE, O_RDONLY); // open file with read-only access
        if (filefd < 0)
        {
            perror("Failed to open file");
            exit(EXIT_FAILURE);
        }

        char buffer[BUFFER_SIZE];
        int n = read(filefd, buffer, BUFFER_SIZE); // read from the file into the buffer
        write(fds[1], buffer, n);                  // write the buffer to the pipe (n is the number of bytes read from the file)
        // this is the write end of the pipe from the child process
    }

    return 0;
}