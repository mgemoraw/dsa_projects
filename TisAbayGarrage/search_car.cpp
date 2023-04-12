
#include "tisabay.h"

extern unsigned int cars;


void search_car(park_t **head)
{

    search_by_plate(*head);
}

park_t *search_by_plate(park_t *head)
{
    park_t *temp = head;
    string p_number;
    cout << "\nEnter Vehicle Plate No:";
    getline(cin, p_number);

    if(head == NULL)
    {
        cout << "\n..............No Vehicles in the Queue .................\n";
        return NULL;
    }
    while (temp != NULL && p_number != temp->plate_number)
    {
        temp = temp->next; 
    }
    

return temp;
}


void use_car_urgent(park_t *head)
{
    string p_number;
    park_t *car, *temp1, *temp2;
    int use_option;

    
    if (head == NULL)
    {
        cout << "\n..............No Vehicles in the Queue .................\n";
        return ;
    }

    cout << "\n Enter vehicle License No:";
    getline(cin, p_number);


    if (head->next == NULL && head->plate_number == p_number)
    {
        car = head;
    }
    else
    {
        car = head;
        while (car->next != NULL && car->next->plate_number != p_number)
        {
            car = car->next;
        }

        temp1 = car-next;
        temp2 = car->next;
        temp1->next = temp2;

        cars--;
    }
    
    // check for car if not available
    if (car == NULL)
    {
    cout << "\n........No Vehicle with license plate " << p_number << " In The queue .................\n";
    return;
    } 
    
    cout << "\n Do you want to return the car back to the queue? \nYes = 1 / No = 0: ";
    cin >> use_option ;
    cin.ignore(256, '\n');

    if (use_option == 1)
    {
        enqueue(&head, car);
    }
    else
    {
        delete car;
    }
    
}


void re_queue(park_t **head)
{
    (void)head;

}