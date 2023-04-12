#ifndef TOWNS_H
#define TOWNS_H


#include<iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

typedef struct Town
{
    struct Town *prev;
    int index;
    string id;
    string name;
    string description;
    double dist_from_bdr;
    double dist_from_aa;
    string longitude;
    string latitude;
    struct Town *next;
    
} town_t;

//add new town
void add_town(town_t **town);
void add_new_town(town_t **town);
town_t *search_town(town_t *town, string town_name);
town_t *delete_town(town_t *town, string town_name);
void display_all_records(town_t *town);

// origin destination
void origin_dest(town_t **town);


//display records
void print_records(town_t **head);
void search_town(town_t *head);
town_t *search_by_id(town_t *head);
town_t *search_by_name(town_t *head);
town_t *search_by_name(town_t *head, string town_name);

void display_town_info(town_t *town);

//dedelete records
void delete_record(town_t **head);
void delete_by_id(town_t **head);
void delete_by_name(town_t **head);
void free_all_records(town_t **head);

// utility functions
void print_menu();
void print_frame();
void print_header();

#endif
