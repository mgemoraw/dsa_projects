#ifndef TOWNS_H
#define TOWNS_H


#include<iostream>

using std::string;
using std::cout;
using std::cin;


typedef struct Town
{
    struct Town *prev_town;
    int index;
    string name;
    double dist_from_prev;
    double dist_from_next;
    double longitude;
    double latitude;
    struct Town *next_town;
    
} town_t;


town_t *add_new_town(town_t *town);
town_t *search_town(town_t *town, string town_name);
town_t *delete_town(town_t *town, string town_name);
void display_all_records(town_t *town);

town_t origin_destination(town_t *town, string origin, string destination);

// utility functions
void print_menu();
void print_frame();
void print_header();

#endif
