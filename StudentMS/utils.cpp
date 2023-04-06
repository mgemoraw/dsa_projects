#include "student.h"

void print_menu()
{
    std::cout << "#####################################################\n";
    std::cout << "\t Enter Option\n";
    std::cout << "\t 0: to exit the system\n";
    std::cout << "\t 1: add student\n";
    std::cout << "\t 2: View All Records\n";
    std::cout << "\t 3: delete student\n";
    std::cout << "\t 4: Delete All Records\n";
    std::cout << "\t 5: Remove Dismissals\n";
    std::cout << "\t 6: Search Student\n";
    std::cout << "\t 7: Sort Records\n";
    std::cout << "\t 8: View Number Records\n";
    std::cout << "#####################################################\n";

    std::cout << "Select Menu Operation: ";
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

    std::cout << "\n\n----------------------------------------------------------------------------------------------\n";
    printf("%-10s %-10s %-20s %-20s %-10s %-10s %-20s\n", "index", "ID No.", "First Name", "Last Name", "Sex", "CGPA","Status");
    // printf("%-10d %-10s %-20s %-20s %-10.2lf %-10c %-20s \n", index, (head->id).c_str(), (head->fname).c_str(), (head->lname).c_str(),head->sex, head->CGPA, (head->status).c_str() );

    // std::cout << " No\t ID\t First Name\t ";
    // std::cout <<"Last Name \tSex \tCGPA \tStatus\n";
    std::cout <<"----------------------------------------------------------------------------------------------\n";
}


