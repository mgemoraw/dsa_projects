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



// enqueue operations

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


// searching

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

        temp1 = car->next;
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



// stack operations
void pop(park_t **head)
{
    (void)head;

}
void push(park_t **head)
{
    (void)head;

}
bool is_empty(park_t **head)
{
    (void)head;

    return true;
}
void re_queue(park_t **head)
{
    (void)head;

}
