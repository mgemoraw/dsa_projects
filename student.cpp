#include "student.h"

int main(void)
{
    student_t *head = NULL;

    int option = 0;

    do {
        print_menu();
        std::cin >> option;
        switch (option)
        {
            case 0:
                break;
            case 1:
                head = add_student(head);
                break;
            case 2:
                print_data(head);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                std::cout << "Invalid Menu! Please select the right Operation!";
                break;
        }
    } while (option != 0);

    return (0);
}

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

    node->status = "";
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

    numberOfStudents++;
    }

    return head;
}
student_t *dismiss_student(student_t *head)
{
    return NULL;
}
void print_data(student_t *head)
{
    size_t index = 1;
    if (head == NULL)
    {
        std::cout << "Database Empty!\n";
        return;
    }
    student_t *temp = head;

    print_header();

    while (temp != NULL)
    {
        std::cout << index << "   ";
        std::cout << temp->id << "\t";
        std::cout << temp->fname << "\t";
        std::cout << temp->lname << "\t";
        std::cout << temp->sex << "\t";
        std::cout << temp->CGPA << "\t";
        std::cout << temp->status << "\t\n";

        index++;
        temp = temp->next;

    }
    std::cout <<"\n\n";
    return;
}
void search_student(student_t *head, string name)
{

}
void sort_by_name(student_t *head)
{
   
}
void sort_by_id(student_t *head)
{
    
}
void delete_by_id(student_t *head)
{

}
