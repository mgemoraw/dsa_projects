#include "dec_bin.h"
#include <string>

int dec_counter = 0; // global variable to track number of decimal places
int prec_counter = 0; // global variable to track precision

/**
* main - main function
*
* Return: Always 0
*/
int main(void)
{
    tobin_t *head = NULL;
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
                display(head);
                break;
            default:
                cout << "\nInvalid Operation. Please choose the right operation\n";
                break;

        }
    } while (option != 0);
    
    head = free_nodes(&head); // free nodes
    
    return (0);
}



/**
* print_menu - prints menu string
* Return: returns nothing
*/
void print_menu()
{
   cout << "\n#####################################################\n";
   cout << "\t WELCOME TO DECIMAL TO BINARY CONVERSION SYSTEM\n";
   cout << "\t Enter Operation Option\n";
   cout << "\t 0: to exit the system\n";
   cout << "\t 1: To convert to Binary and Display\n";
   cout << "#####################################################\n";
   cout << "Select Operation: ";
}


/**
* free_nodes - deallocates all memory allocated for storage of binary digits 
* @head: pointer to head of te stack
* Return: returns nothing
*/
void convert_to_decimal(tobin_t **head)
{
    tobin_t *temp  = *head;
    tobin_t *node = new tobin_t;
    double number;
    int rem, d_rem, precision = 0;
    

    cout << "\n Enter Integer Number: \n";
    cin >> number;

    cin.ignore(256, '\n');

    if (number < 0) {
        cout << "\nYou are changing negative number to binary!\n";
        number = - number;
    }

    // handling decimal and integer parts separately
    int int_num = (int)number;
    double dec_num = number - int_num;
    dec_counter = 0;
    
    if (number >= 0 && number <= 1)
    {  
        *head = add_head(head, number);
        dec_counter++;
        return;
    }
   
    do
    {
        rem = int_num % 2;

        *head = add_head(head, rem);

        int_num = int_num / 2;
        dec_counter++;
    } while (int_num > 0);

    // adding decimal binaries to the stack
     do {
        dec_num = dec_num * 2;
        int d_rem = (int) dec_num;
        // cout << d_rem;
        *head = add_precision(head, d_rem);

        dec_num = dec_num - d_rem;
        precision++;
    }while (dec_num > 0 || precision < 10);

    return;
}

/**
* add_head - adds binary bit of a decimal number to the stack 
* @head: pointer to head of te stack
* @data: binary bit to be added
* Return: returns head of the stack
*/
tobin_t *add_head(tobin_t **head, int data)
{
    tobin_t *temp; // = *head;
    tobin_t *node = new tobin_t;

    if (node == NULL)
        return NULL;

    node->bit = data;
    node->next = NULL;

    if (*head == NULL)
    {
        *head = node;
        return node ;// head;
    }
    else {
        node->next = *head;
        *head = node;
    }
    

    return node; // node;
}


/**
* add_precision - adds binary of decimal precisions to the stack as a queue 
* @head: pointer to head of te stack
* @data: binary bit to be added
* Return: returns head of the stack
*/
tobin_t *add_precision(tobin_t **head, int data)
{
    tobin_t *temp = *head, *node;

    node = new tobin_t;

    if (node == NULL)
        return NULL;

    node->bit = data;
    node->next = NULL;

    if (*head == NULL) {
        *head = node;
        return *head;
    }

    if ((*head)->next == NULL)
    {
        (*head)->next = node;
        return *head;
    }

    
    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = node;
    

    return *head;
}


/**
* display - displays all binary digits of any decimal number stored in the tack
* @head: pointer to head of te stack
* Return: returns nothing
*/
void display(tobin_t *head)
{
  
  int counter = 0;
    convert_to_decimal(&head);


    if (head == NULL) // (head))
    {
        std::cout << "\n......No Data!......\n";
        return;
    }

    tobin_t *temp = head;

    cout << "\n Binary Form of number is: ";
    while (temp != NULL && counter < dec_counter)
    {
        cout << temp->bit;
        temp = temp->next;
        counter++;
    }

    // this prints precision queue
    cout << ".";
    while (temp != NULL)
    {
        cout << temp->bit;
        temp = temp->next;
    }

    cout <<"\n";
    return;
}


/**
* free_nodes - deallocates all memory allocated for storage of binary digits 
* @head: pointer to head of te stack
* Return: returns head of the stack
*/
tobin_t *free_nodes(tobin_t **head)
{
    tobin_t *temp;

    while ((*head) != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        delete temp;
    }

    return NULL;
}


/**
* dec_to_bin - adds binary of decimal precisions to the stack as a queue 
* @number: decimal number
* Return: returns nothing
*/
void dec_to_bin(double number)
{
    int int_num = (int) number;
    double dec_num = number - int_num;
    int d_rem;
    int precision  = 0;
    
    cout << int_num << "..." << dec_num << "\n";
    int rem;
    do {
        rem = int_num % 2;

        cout << rem;
        int_num = int_num / 2 ;
    }while (int_num > 0);

    cout << ".";
    do {
        dec_num = dec_num * 2;
        int d_rem = (int) dec_num;
        cout << d_rem;
        dec_num = dec_num - d_rem;
        precision++;
    }while (dec_num > 0 || precision < 10);

}