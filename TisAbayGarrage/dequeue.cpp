#include "tisabay.h"


extern unsigned int cars;
// queue operations

void dequeue(park_t **head)
{
    park_t *temp = *head;
    string p_number;

    temp = new park_t;

    if (*head == NULL)
    {
        cout << "\n ......... Woohooo!  No Car/s is Waiting You...........\n";
        return;
    }
    
    if ((*head)->next == NULL)
    {
        p_number = (*head)->plate_number;
        temp = *head;
        *head = NULL;
        delete temp;
    }
    else
    {
        p_number = (*head)->plate_number;
        temp = (*head);

        delete (temp);

        *head = (*head)->next;
       
    }
   
    cout << "\n Car with Plate number " << p_number << " surved successfully\n";
    
    if (*head == NULL)
    {
        cout << "\n ......... Woohooo!  All Cars Are Served...........\n";
    }
    cars--;

}