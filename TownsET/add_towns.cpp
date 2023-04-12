#include "towns.h"

extern size_t town_number;
extern town_t **tail;

/**
 * add_record - calls add_student function every time when adding record is requested
 * 
 * @param head 
 * @return head
 */
void add_town(town_t **head)
{
    int aOption = 1;

    add_new_town(head);

    while (aOption != 0)
    {
        cout << "\nAdd Another Record (yes = 1, No = 0)? \n";
        cin >> aOption;
        cin.ignore(256, '\n');

        if (aOption == 1)
        {
            add_new_town(head);
            continue;
        }
        else
            break;
        
    }
    
    return; 
}

/**
 * add_student - adds student to the database
 * 
 * @head: head of the list 
 * Return: returns head of the list after addition 
 */
void add_new_town(town_t **head)
{
    town_t *node = new town_t;
    town_t *temp = *head, *temp2;
    // char new_line;
    

    cout << "Enter Town Information\n";
    cout << "Enter Unique Town id: ";
    // new_line = cin.get();
    getline(cin, node->id); //getline(cin >> ws, name);

    cout << "Enter Town Name: ";
    getline(cin, node->name);

    // getchar();

    cout << "Enter Description ";
    getline(cin, node->description);

    cout << "Enter Longitude: ";
    getline(cin, node->longitude);
    
    // getchar();

    cout << "Enter Latitude: ";
    getline(cin, node->latitude);

    // getchar();
    cout << "Enter distance from Bahir Dar(km): ";
    cin >> node->dist_from_bdr;

    //distance from aa = 565 - distance from bdr
    node->dist_from_aa = 565.00 - node->dist_from_bdr;

    cin.ignore(256, '\n');

    
    
    node->prev = NULL;
    node->next = NULL;


    if (*head == NULL)
    {
        *head = node;
        return;
    }

    while (temp->prev != NULL)
        temp = temp->prev;
    
    if (temp->next == NULL && temp->dist_from_bdr < node->dist_from_bdr)
    {
        node->index = 0;
        node->next = temp;
        temp->prev = node;
        temp->index += 1 ;
        *head = node;
        return;
    }
    else
    {
        while (temp->dist_from_bdr < node->dist_from_bdr)
        {
            temp = temp->next;
        }
        
        node->index = temp->index - 1;

        // This adds a town before a town
        temp2 = temp->prev;
        temp2->next = node;
        node->next = temp;
        node->prev = temp2;
        temp->prev = node;
        

        //This adds town after current town;
        /*
        // temp2 = new town_t;
        temp2 = temp->next;
        temp->next = node;
        // temp2->prev = node;
        node->next = temp2;
        node->prev = temp;
        */

    }
   

   
    while (temp->prev != NULL)
        temp = temp->prev;

    *head = temp;

    town_number++;
    // write_log(node);

    return;
}
