#indef TOWNS_H
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
    double area;
    double length;

    struct Town *next_town;
} town_t;


#endif
