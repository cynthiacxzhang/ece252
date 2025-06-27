// Basic Pipe

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Creating a pipe between a parent and a child, then sending data down that pipe

int main()
{
    int n;
    int fd[2];
    pid_t pid;
    char line[100];

    if (pipe(fd) == -1)
    {
        printf("Pipe failed\n");
        return 1;
    }

    if ((pid = fork()) == -1)
    {
        printf("Fork failed\n");
        return 1;
    }

    if (pid > 0)
    {
        close(fd[0]); // close read end
        write(fd[1], "Hello", 5);
    }
    else
    {
        close(fd[1]); // close write end
        n = read(fd[0], line, 100);
        write(STDOUT_FILENO, line, n);
    }

    exit(0);
}