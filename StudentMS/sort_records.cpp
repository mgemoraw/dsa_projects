#include "student.h"

/**
 * sort_records - sorts records by id or by name
 * 
 * @head: head of the list 
 * Return: returns nothing
 */
void sort_records(student_t *head)
{
    int soption = 0;

    if (head == NULL)
    {
        std::cout << "No Records Available\n";
        return;
    }
    do {
        std::cout << "Select Options\n";
        std::cout << "\t 1: sort by Id\n";
        std::cout << "\t 2: sort by first name\n";
        std::cout << "\t 0: to cancel\n";
        std::cout <<"Enter Sort Option: ";

        std::cin >> soption;
        switch (soption)
        {
            case 0:
                break;
            case 1:
                sort_by_id(head);
                break;
            case 2:
                sort_by_name(head);
                break;
            default:
                std::cout << "Invalid Choice\n";
                break;
        }  
    } while (soption != 0);   
}



void sort_by_name(student_t *head)
{
    (void)head;
}
void sort_by_id(student_t *head)
{
    (void)head;
}
