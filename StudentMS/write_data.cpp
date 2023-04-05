// #include "student.h"
#include<iostream>
#include<fstream>
#include <cstdio>


using namespace std;
// using std::ios;

typedef struct Student
{
    struct Student *prev;
    string id;
    string fname;
    string lname;
    char sex;
    float CGPA;
    string status;
    struct Student *next;
} student_t;


void write_to_file(student_t *head)
{
    student_t *temp = head;
    FILE *fp;

    fp = fopen("exported.txt", "w");

   // student.open("student.txt", ios::out); // write mode

    int index = 0;

    fprintf(fp, "%-10s %-10s %-20s %-20s %-10s %-10s %-20s\n", "index", "ID No.", "First Name", "Last Name", "Sex", "CGPA","Status");
    fprintf(fp, "...............................................\n");
    while (temp!= NULL)
    {
        fprintf(fp, "%-10d %-10s %-20s %-20s %10c %-10.2lf %-20s \n", index, (head->id).c_str(), (head->fname).c_str(), (head->lname).c_str(),head->sex, head->CGPA, (head->status).c_str());
        temp = temp->next;
    }   


    /*
    if (student.is_open()) {
        while (temp != NULL)
        {
            student << index;
            student << "    ";
            student << temp->id << "\t";
            student << temp->fname << "\t";
            student << temp->lname << "\t";
            student << temp->sex << "\t";
            student << temp->CGPA << "\t";
            student << temp->status << "\t\n";

            index++;
            temp = temp->next;
        }
        student << "\n";;

        student.close();
    }
    */


}


void write_log(student_t *head)
{
    fstream log;
    FILE *fp;
    int index = 0;
    // log.open("__log__.txt");
    if (!log)
    {
        log.open("__log__.text", ios::out);
        log.close();
    }
    fp = fopen("__log__.txt", "a");
    
    fprintf(fp, "%s %s\n", "[new Log", "operation: Appended]");
    fprintf(fp, "%-10d %-10s %-20s %-20s %10c %-10.2lf %-20s \n", index, (head->id).c_str(), (head->fname).c_str(), (head->lname).c_str(),head->sex, head->CGPA, (head->status).c_str());

    fclose(fp);
  /*
  log.open("__log__.text", ios::out);

  if (log.is_open())
  {
    log << "\n" << node->id;
    log << "\t" << node->fname;
    log << "\t" << node->lname;
    log << "\t" << node->sex;
    log << "\t" << node->CGPA;
    log << "\t" << node->status;
    log << "\n";
  } 

  log.close();
  */
}

/*
int main()
{

    fstream student;
    student_t *head ;
    head = new student_t;
    FILE *fp;
    head->id = "001";
    head->fname = "forsest";
    head->lname = "langoaon";
    head->sex = 'M';
    head->CGPA = 1.5;
    head->next = NULL;
    head->status = "Dismissal";

    student.open("student.txt", ios::out); // write mode

    fp = fopen("try.txt", "w");
    if (student.is_open()) 
    {
        student <<"firist line\n";
        student << "second line" << std::endl;

        student.close();
    }
    int index = 0;
    string name  = "thie is y nem";
    
    printf("%-10s %-10s %-20s %-20s %-10s %-10s %-20s\n", "index", "ID No.", "First Name", "Last Name", "Sex", "CGPA","Status");
    printf("%-10d %-10s %-20s %-20s %-10.2lf %-10c %-20s \n", index, (head->id).c_str(), (head->fname).c_str(), (head->lname).c_str(),head->sex, head->CGPA, (head->status).c_str() );


    // 
    // printf("This is %10s %10s %10s \n", "ID No",  "Frst Name", "CGPA");
    // printf("This is %10s %10s %lf \n", (head->id).c_str(),  (head->fname).c_str(), head->CGPA);
    // printf("%s \n", "name");
    // printf("%s \n", (head->id).c_str());


    // %[flags][width][.precision][length]  //specifiers for printf
    //
    return 0;

}

*/

