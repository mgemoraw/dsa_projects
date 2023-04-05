#include "student.h"
extern size_t numberOfStudents;


/**
 * remove_dismisals - removes all sudents under accademic dismisal
 * 
 * @head: head of the list 
 * Return: returns list of students with no dismissals
 */
student_t *remove_dismisals(student_t *head)
{
	student_t *current = head, *temp, *temp1;
	size_t count = 0;
	// temp = new student_t;

    (void)temp1;
	if (head == NULL)
		return NULL;

    if (current->next == NULL)
    {
        if (current->CGPA <= MIN_CGPA) 
        {
            delete current;
            count++;
            current = NULL;
        }
    }
    while (current->next != NULL)
    {
        if (current->CGPA <= MIN_CGPA)
        {
            temp = current;
            temp1 = new student_t;

            temp1 = current->prev;
            current = current->next;
            current->prev = temp1;

            delete temp;
            // temp = NULL;
            temp1 = NULL;
			count++; 
        }
        else 
        {
            current = current->next;
        }
    }

    if (current != NULL && current->CGPA <= MIN_CGPA) 
    {
        temp = current->prev;
        temp->next = NULL;
        delete current;
        current = temp;
        temp = NULL;
        count++;
    }

    

    
    if (is_empty(current) == false)
    {
        while(current->prev != NULL)
            current = current->prev;
    }
    
   
	std::cout << "\n......" << count << " students dismissed........\n";
	numberOfStudents -= count;


	return (current);   
}

/**
 * check_accademic_status - checks the accademic status of the student
 * 
 * @head: head of the list 
 * Return: returns status (Dismissal, Warning, Pass, Distiniction)
 */
string check_accademic_status(double gpa)
{
    string status;

    if (gpa <= MIN_CGPA)
        status = "Dismissal";
    else if (gpa < 2.0)
        status = "Warning!";
    else if (gpa <= 3.5)
        status = "Pass!";
    else if (gpa <= 4.0)
       status = "Distiniction!";
    else 
       status = "(nil)";

    return status;
}


