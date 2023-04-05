#include "student.h"

extern size_t numberOfStudents;

/**
 * add_record - calls add_student function every time when adding record is requested
 * 
 * @param head 
 * @return head
 */
student_t *add_record(student_t *head)
{
    int aOption = 1;

    head = add_student(head);

    while (aOption != 0)
    {
        std::cout << "\nAdd Another Record (yes = 1, No = 0)? \n";
        std::cin >> aOption;
        if (aOption == 1)
        {
            head = add_student(head);
            continue;
        }
        else
            break;
        
    }
    
    return head; 
}

/**
 * add_student - adds student to the database
 * 
 * @head: head of the list 
 * Return: returns head of the list after addition 
 */
student_t *add_student(student_t *head)
{
    student_t *node = new student_t;
    student_t *temp = head;

    std::cout << "Enter the required information of the student\n";
    std::cout << "Enter student id: ";
    std::cin >> node->id;

    std::cout << "Enter student first name: ";
    std::cin >> node->fname;

    std::cout << "Enter student last name: ";
    std::cin >> node->lname;

    std::cout << "Enter sex: ";
    std::cin >> node->sex;

    std::cout << "Enter CGPA: ";
    std::cin >> node->CGPA;

    node->status = check_accademic_status(node->CGPA);
    
    node->prev = NULL;
    node->next = NULL;


    if (head == NULL)
    {
        head = node;
    }
    else 
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
    }
    numberOfStudents++;
    write_log(node);

    return head;
}
