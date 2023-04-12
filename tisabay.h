#ifndef TISABAY_H
#define TISABAY_H


#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>

using namespace std;


typedef struct Park
{
    unsigned int rno;
    string plate_number;
    string car_type;
    string owner_name;
    string arrival_time;
    string depart_time;

    struct Park *next;

} park_t;

// enqueue operations
void enqueue(park_t **head);
void enqueue(park_t **head, park_t *car);

// earch operations
park_t *search_by_plate(park_t *head);
void search_car(park_t **head);

// dequeue operations
void dequeue(park_t **head);
void all_served(park_t *head);

// re-queue operations
void use_car_urgent(park_t *head);
void re_queue(park_t **head);


// stack operations
void pop(park_t **head);
void push(park_t **head);
bool is_empty(park_t **head);

// display queue
void display_queue(park_t *head);
void print_header();


void print_menu();

#endif
