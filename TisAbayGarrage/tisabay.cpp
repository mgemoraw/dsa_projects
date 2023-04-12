#include "tisabay.h"

unsigned int cars = 0;
park_t *head = NULL, *tail = NULL;


int main(void)
{

    int option;
    
    do {

        print_menu();
        cin >> option;
        cin.ignore(256, '\n');

        switch(option)
        {
            case 0:
                cout << "\n......exiting from system........\n";
                break;
            case 1:
                enqueue(&head);
                break;
            case 2:
                display_queue(head);
                break;
            case 3:
                dequeue(&head);
                break;
            case 4:
                search_car(&head);
                break;
            case 5:
                use_car_urgent(head);
                break;
            case 6:
                all_served(head);
                break;
            default:
                cout << "\nInvalid Operation. Please choose the right operation\n";
                break;

        }
    } while (option!= 0);
    
    return (0);
}





void print_menu()
{
   cout << "#####################################################\n";
   cout << "\t Enter Operation Option\n";
   cout << "\t 0: to exit the system\n";
   cout << "\t 1: Park new Car\n";
   cout << "\t 2: View queue \n";
   cout << "\t 3: Serve First Car\n";
   cout << "\t 4: Search Car\n";
   cout << "\t 5: Use Car for Urgent\n";
   cout << "\t 6: Delete All Records\n";
   cout << "#####################################################\n";
   cout << "Select Operation: ";
}

