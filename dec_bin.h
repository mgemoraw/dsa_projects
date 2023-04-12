#ifndef TOBINARY_H
#define TOBINARY_H

#include <iostream>


using namespace std;

typedef struct DecimalToBinary 
{
int bit;
struct DecimalToBinary *next;
} tobin_t;



void convert_to_decimal(tobin_t **head);
void display(tobin_t *head);
void print_menu();

tobin_t *add_head(tobin_t **head, int data);
tobin_t *add_precision(tobin_t **head, int data);
void dec_to_bin(double number);

tobin_t *free_nodes(tobin_t **head);

#endif