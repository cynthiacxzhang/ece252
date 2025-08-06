#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct
{
    int number;
    double lecture_hours;
    double tutorial_hours;
    double lab_hours;
    double credits;
    double au;      // accreditation units (AU)
    char mandatory; // 0 for no, 1 for yes
} ece_course;

// Program: open file, read one ece_course sized chunk at a time
// - interpret it as an ece_course struct
// - input: course number (ex: 254)
// - output: number of accreditation units (AU) for that course
// - if a course matches the input number, print the associated AU to the console
// - if no match, print "Course not found" and return -1

int main(int argc, char *argv[])
{
    int course = atoi(argv[1]);                // ascii to int
    int fd = open("courses.dat", O_RDONLY);    // open file with read-only access
    char *buffer = malloc(sizeof(ece_course)); // allocate memory for one course

    int bytes_read = read(fd, buffer, sizeof(ece_course)); // read one course

    while (bytes_read != 0)
    {

        ece_course *course_ptr = (ece_course *)buffer; // casting buffer as ece_course
        if (course_ptr->number == course)
        { // check if course number matches
            printf("AUs: %g\n", course_ptr->au);
            free(buffer); // free allocated memory
            close(fd);    // close file descriptor
            return 0;     // exit successfully
        }

        // bytes_read = read(fd, buffer, sizeof(ece_course)); // read next course
    }

    printf("Course not found\n");
    free(buffer);
    close(fd);
    return -1; // course not found
}
