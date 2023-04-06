#include "student.h"

size_t numberOfStudents = 0;

// Main function
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
                head = add_record(head);
                break;
            case 2:
                print_data(head);
                break;
            case 3:
                head = delete_record(head);
                break;
            case 4:
                free_all_records(&head);
                break;
            case 5:
                head = remove_dismisals(head);
                break;
            case 6:
                search_student(head);
                break;
            case 7:
                sort_records(head);
                break;
            case 8:
                print_count();
                break;
            default:
                std::cout << "Invalid Menu! Please select the right Operation!\n";
                break;
        }
    } while (option != 0);

    return (0);
}



void print_count()
{
    std::cout << "\nTotal Number of Students: " << numberOfStudents << "\n";
}

bool is_empty(student_t *node)
{
    if (node != NULL)
        return false;
    else
        return true;

}

