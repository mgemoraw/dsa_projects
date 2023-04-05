#include "student.h"

/**
 * print_data - prints all recods in the database
 * 
 * @head: head pointer of the list
 * Return: returns nothing
 */
void print_data(student_t *head)
{
    size_t index = 1;

    if (is_empty(head))
    {
        std::cout << "Database Empty!\n";
        return;
    }

    student_t *temp = head;

    print_header();

    while (temp != NULL)
    {
        /*
        std::cout << index << "   ";
        std::cout << temp->id << "\t";
        std::cout << temp->fname << "\t";
        std::cout << temp->lname << "\t";
        std::cout << temp->sex << "\t";
        std::cout << temp->CGPA << "\t";
        std::cout << temp->status << "\t\n";
        */
        printf("%-10ld %-10s %-20s %-20s %-10c %-10.2lf %-20s \n", index, (head->id).c_str(), (head->fname).c_str(), (head->lname).c_str(),head->sex, head->CGPA, (head->status).c_str());
        index++;
        
        temp = temp->next;

    }
    std::cout <<"\n\n";
    return;
}

