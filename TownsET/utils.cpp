#include "towns.h"

void print_menu()
{
   cout << "#####################################################\n";
   cout << "\t Enter Operation Option\n";
   cout << "\t 0: to exit the system\n";
   cout << "\t 1: Add Town\n";
   cout << "\t 2: View All Records\n";
   cout << "\t 3: Delete Town\n";
   cout << "\t 4: Search Town\n";
   cout << "\t 5: Find Origin Destination Distance\n";
   cout << "\t 6: Delete All Records\n";
   cout << "#####################################################\n";

   cout << "Select Operation: ";
}


void print_frame()
{
    int row, col;

    for (row = 0; row < 10; row++)
    {
        for (col = 0; col < 20; col++)
        {
           cout << "#";
        }
    }
}


