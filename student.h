#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <string.h>

// include standard sring of c++
using std::string;


// define grade limit
#define MIN_CGPA 1.75

static int numberOfStudents = 0;
typedef struct Student
{
    struct Student *prev;
    string id;
    string fname;
    string lname;
    char sex;
    float CGPA;
    string status;
    struct Student *next;
} student_t;

// list operation functions
student_t *add_student(student_t *head);
student_t *dismiss_student(student_t *head);
void print_data(student_t *head);
void search_student(student_t *head, string name);

//sorting functions
void sort_by_name(student_t *head);
void sort_by_name(student_t *head);

// deleting functions
void delete_by_id(student_t *head);

// utility functions
void print_menu();
void print_frame();
void print_header();


#endif