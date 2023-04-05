#include "../student.h"

size_t numberOfStudents = 0;
int main(void)
{
    student_t *head = NULL, *a, *b, *c, *d;

    head = new student_t;
    a = new student_t;
    b = new student_t;
    c = new student_t;
    d = new student_t;
    (void)c;
    (void)d;
    (void)b;

    head->id = "001";
    head->CGPA = 1.5;
    head->next = a;

    a->prev = head;

    a->id = "002";
    a->CGPA = 1.2;
    a->next = NULL; //a->next = b;

    // b->prev = a;
    
    // b->id = "003";
    // b->CGPA = 2.0;
    // b->next = NULL;

    print_data(head);
    head = remove_dismisals(head);
    // print_data(head);

    std::cout << "\t" << head->CGPA<<std::endl;

    // std::cout << (head == NULL) << "\t";
    // std::cout << (head->next == NULL);
 
    return 0;

}

void print_header()
{

    std::cout << "\n\n----------------------------------------------------------------------\n";
    std::cout << " No\t ID\t First Name\t ";
    std::cout <<"Last Name \tSex \tCGPA \tStatus\n";
    std::cout << "----------------------------------------------------------------------\n";
}

bool is_empty(student_t *node)
{
    if (node != NULL)
        return false;
    else
        return true;

}


void delete_node(student_t *node)
{
    student_t *temp, *current;

    
}