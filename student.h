#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <string.h>

// include standard sring of c++
using namespace std;


// define grade limit
#define MIN_CGPA 1.75

// size_t numberOfStudents = 0;


typedef struct Student
{
    struct Student *prev;
    string id;
    string fname;
    string lname;
    string sex;
    float CGPA;
    string status;
    struct Student *next;
} student_t;

// list operation functions
student_t *add_record(student_t *node);
student_t *add_student(student_t *head);
student_t *remove_dismisals(student_t *head);
void print_data(student_t *head);
void search_student(student_t *head, string name);
void print_count();

void free_all_records(student_t **head);
string check_accademic_status(double gpa);



// searching by id and by name
void search_student(student_t *head);
void search_by_id(student_t *head);
void search_by_name(student_t *head);

//sorting functions
student_t *sort_records(student_t *head);
student_t *sort_by_name(student_t *head);
student_t *sort_by_id(student_t *head);

// deleting functions
student_t *delete_by_id(student_t *head);
student_t *delete_by_name(student_t *head);

// utility functions
void print_menu();
void print_frame();
void print_header();


// write files
void write_log(student_t *head);
void write_to_file(student_t *head);


//swap nodes
void swap_nodes(student_t *node1, student_t *node2);

// check if empty
bool is_empty(student_t *node);
#endif
