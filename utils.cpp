#include "student.h"

void print_menu()
{
    std::cout << "#####################################################\n";
    std::cout << "\t Enter Option\n";
    std::cout << "\t 0: to exit the system\n";
    std::cout << "\t 1: add student\n";
    std::cout << "\t 2: View Data in the Database\n";
    std::cout << "\t 3: delete student by id\n";
    std::cout << "\t 4: delete student by name\n";
    std::cout << "\t 5: Check Academic Status\n";
    std::cout << "\t 6: Remove Dismissals\n";
    std::cout << "\t 7: Search Student by id\n";
    std::cout << "\t 8: Search Student by name\n";
    std::cout << "#####################################################\n";

    std::cout << "Select Operation: ";
}


void print_frame()
{
    int row, col;

    for (row = 0; row < 10; row++)
    {
        for (col = 0; col < 20; col++)
        {
            std::cout << "#";
        }
    }
}

void print_header()
{

    std::cout << "\n\n----------------------------------------------------------------------\n";
    std::cout << " No\t ID\t First Name\t ";
    std::cout <<"Last Name \tSex \tCGPA \tStatus\n";
    std::cout << "----------------------------------------------------------------------\n";
}
