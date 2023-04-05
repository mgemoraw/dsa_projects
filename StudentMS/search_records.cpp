#include "student.h"

void search_student(student_t *head)
{
    int soption = 0;

    if (head == NULL)
    {
        std::cout << "No Records Available\n";
        return;
    }

    do {
        std::cout << "Select Options\n";
        std::cout << "\t 1: search by Id\n";
        std::cout << "\t 2: search by frist and last name\n";
        std::cout << "\t 0: to cancel\n ";
        std::cout << "Enter Search Option: ";
        
        std::cin >> soption;
        switch (soption)
        {
            case 0:
                break;
            case 1:
                search_by_id(head);
                break;
            case 2:
                search_by_name(head);
                break;
            default:
                std::cout << "Invalid Choice\n";
                break;
        } 
    }while (soption != 0); 
    
     
    
}


void search_by_name(student_t *head)
{
    student_t *temp;
    size_t index = 0;
    string fname, lname;
    
    std::cout << "Enter the first name: ";
    std::cin >> fname;

    std::cout << "Enter Last Name: ";
    std::cin >> lname;

    
    std::cout << "\n\n==========Search Results==========\n";

    temp = head;
    while (temp != NULL)
    {
        if (temp->fname == fname && temp->lname == lname)
        {
            std::cout << index << "   ";
            std::cout << temp->id << "\t";
            std::cout << temp->fname << "\t";
            std::cout << temp->lname << "\t";
            std::cout << temp->sex << "\t";
            std::cout << temp->CGPA << "\t";
            std::cout << temp->status << "\t\n";
        }
        index++;
        temp = temp->next; 
    }
    std::cout << "\n======================\n";

}
void search_by_id(student_t *head)
{
    student_t *temp;
    size_t index = 0;
    string id;
    
    std::cout << "Enter ID: ";
    std::cin >> id;

    temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            std::cout << "\n\n==========Search Results==========\n";
            std::cout << index << "   ";
            std::cout << temp->id << "\t";
            std::cout << temp->fname << "\t";
            std::cout << temp->lname << "\t";
            std::cout << temp->sex << "\t";
            std::cout << temp->CGPA << "\t";
            std::cout << temp->status << "\t\n";
        }
        index++;
        temp = temp->next; 
    }
    std::cout << "\n======================\n";
}
