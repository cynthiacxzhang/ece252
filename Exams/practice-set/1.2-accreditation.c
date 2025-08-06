#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
