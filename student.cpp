#include "student.h"

size_t numberOfStudents = 0;

int main(void)
{
    student_t *head = NULL;
    //head = new student_t;

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
                head = delete_by_id(head);
                break;
            case 4:
                head = delete_by_name(head);
                break;
            case 5:
                free_all_records(&head);
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                print_count();
                break;
            default:
                std::cout << "Invalid Menu! Please select the right Operation!\n";
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


    return head;
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
student_t *delete_by_id(student_t *head)
{
    student_t *current = head, *temp;
    string id;

    temp = new student_t;

    if (head == NULL)
        return NULL;
    
    std::cout << "Enter Id Number of The Student to delete: ";
    std::cin >> id;
    while (current->id != id)
        current = current->next;
    
    temp = current->prev;
    temp->next = current->next;


    while (temp->prev != NULL)
    {
        temp = temp->prev;
    }

    head = temp;
    delete(current);
    numberOfStudents--;
    return (head);
}

student_t *delete_by_name(student_t *head)
{
    student_t *current = head, *temp;
    string fname;
    string lname;

    temp = new student_t;

    if (head == NULL)
        return NULL;
    
    std::cout << "Enter First Name: ";
    std::cin >> fname;
    std::cout << "Enter Last Name: ";
    std::cin >> lname;
    while (current->fname != fname && current->lname != lname)
        current = current->next;
    
    temp = current->prev;
    temp->next = current->next;

    while (temp->prev != NULL)
    {
        temp = temp->prev;
    }

    head = temp;
    delete(current);
    numberOfStudents--;
    return (head);
}

void free_all_records(student_t **head)
{
    //string status[] = {"Distiniction", "Warning", "Pass", "Dismissal"};
    student_t *temp;

    if ((*head) = NULL)
        return ;
  
    while((temp = *head) != NULL)
    { 
        (*head) = temp->next;
        delete(temp); 
    }
    return ;
}

student_t *remove_dismisals(student_t *head)
{
    return NULL;
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


void print_count()
{
    std::cout << "\nTotal Number of Students: " << numberOfStudents << "\n";
}