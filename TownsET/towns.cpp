#include "towns.h"

size_t town_number = 2;

town_t *head, *tail;
/**
* main - main function
*
*/
int main(void)
{
    //town_t *head = NULL, *tail;
    int op = 2;

    head = new town_t;
    tail = new town_t;

    head->index = 0;
    head->id = "ET6000";
    head->name = "Bahir Dar";
    head->description = "Bahir Dar is the capital of regional government of Amhara national regional state";
    head->dist_from_bdr = 0;
    head->dist_from_aa = 565;
    head->latitude = "11.5742° N";
    head->longitude = "37.3614° E";
    head->next = tail;
    head->prev = NULL;


    tail->index = 1;
    tail->id = "ET1000";
    tail->name = "Addis Ababa";
    tail->description = "Addis Ababa is the Capital City of Ethiopia";
    tail->dist_from_bdr = 565;
    tail->dist_from_aa = 0;
    tail->latitude = "11.5742° N";
    tail->longitude = "37.3614° E";
    tail->next = NULL;
    tail->prev = head;


  
    // cout << format();
    do {

        print_menu();
        cin >> op;

        cin.ignore(256, '\n');

        switch(op)
        {
            case 0:
                cout << "\n......exiting from system........\n";
                break;
            case 1:
                add_town(&head);
                break;
            case 2:
                print_records(&head);
                break;
            case 3:
                delete_record(&head);
                break;
            case 4:
                search_town(head);
                break;
            case 5:
                origin_dest(&head);
                break;
            default:
                cout << "Invalid Choice. Please Try again ";
                break;
        }
    } while (op != 0);
    return (0);
}