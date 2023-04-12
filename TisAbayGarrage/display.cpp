#include "tisabay.h"


void display_queue(park_t *head)
{
    unsigned long int index = 1;
    park_t *temp = head;
    (void)index;


    if (head == NULL)
    {
        cout << "\n................Database Empty!..................\n";
        return;
    }

    print_header();
    while (temp != NULL)
    {
        printf("%-5u %-15s %-20s %-20s %-15s %-15s\n", temp->rno, (temp->plate_number).c_str(), (temp->car_type).c_str(), (temp->owner_name).c_str(), (temp->arrival_time).c_str(), (temp->depart_time).c_str() );
        
        temp = temp->next;

    }

   

}

void print_header()
{

    cout << "\n\n------------------------------------------------------------------------------------------------------------\n";
    
    printf("%-5s %-15s %-20s %-20s %-15s %-15s \n", "SNo.", "Plate Number", "Type(Model)", "Owner", "arrival Time", "Departure Time\n");
    cout << "------------------------------------------------------------------------------------------------------------\n";
}