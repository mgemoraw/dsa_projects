#include "tisabay.h"

extern unsigned int cars;
extern park_t *head;

void all_served(park_t *head)
{
    park_t *temp = head;
    if (head == NULL)
    {
        cout << "\n No cars in the queue\n";
        return;
    }

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    cout << "\n ......... Woohooo!  All Cars Serverd...........\n";
    cars = 0;
}