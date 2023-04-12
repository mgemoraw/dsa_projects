#include "tisabay.h"


extern unsigned int cars;
// queue operations

void enqueue(park_t **head)
{
    park_t *temp = *head, *new_car;
    unsigned int index = 0;

    new_car = new park_t;
    cout << "Enter Car Plate No:";
    getline(cin, new_car->plate_number);

    cout << "Enter Car Type: ";
    getline(cin, new_car->car_type);

    cout << "Enter Car owner name: ";
    getline(cin, new_car->owner_name);

    cout << "Enter Car arrival time: ";
    getline(cin, new_car->arrival_time);

    cout << "Enter Car Departure Time ";
    getline(cin, new_car->depart_time);

    new_car->next = NULL;
    // new_car->rno = cars;
    

    
    if (*head == NULL)
    {
        new_car->rno = 1;
        *head = new_car;
        return ;
    }

    if (temp->next == NULL)
    {
        temp->next = new_car;
        new_car->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
            index++;
        }
        temp->next = new_car;
        new_car->next = NULL;
        new_car->rno = index;
    }

    
}



void enqueue(park_t **head, park_t *car)
{
    (void)head;
    (void)car;
    park_t *temp = *head;
    if (*head == NULL)
    {
        *head = car;
        return;
    }

    if ((*head)->next == NULL)
    {
        (*head)->next = car;
        car->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = car;
        car->next = NULL;
    }
    
   
}
