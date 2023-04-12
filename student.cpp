#include "student.h"

size_t numberOfStudents = 0;

int main(void)
{
    student_t *head = NULL;
    //head = new student_t;

    int option = 0;

    do {
        print_menu();
        cin >> option;
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
                head = delete_by_id(head);
                break;
            case 4:
               head = delete_by_name(head);
                break;
            case 5:
                free_all_records(&head);
                break;
            case 6:
               head = remove_dismisals(head);
                break;
            case 7:
                search_student(head);
                break;
            case 8:
               sort_records(head);
                break;
            case 9:
                print_count();
                break;
            default:
                cout << "Invalid Menu! Please select the right Operation!\n";
                break;
        }
    } while (option != 0);

    return (0);
}


void print_count()
{
    cout << "\nTotal Number of Students: " << numberOfStudents << "\n";
}

bool is_empty(student_t *node)
{
    if (node == NULL)
        return true;
    else
        return false;
}


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
        cout << "\nAdd Another Record (yes = 1, No = 0)? \n";
        cin >> aOption;
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

    cout << "Enter the required information of the student\n";
    cout << "Enter student id: ";
    cin >> node->id;

    cout << "Enter student first name: ";
    cin >> node->fname;

    cout << "Enter student last name: ";
    cin >> node->lname;

    cout << "Enter sex: ";
    cin >> node->sex;

    cout << "Enter CGPA: ";
    cin >> node->CGPA;

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


void print_menu()
{
    cout << "#####################################################\n";
    cout << "\t Enter Option\n";
    cout << "\t 0: to exit the system\n";
    cout << "\t 1: add student\n";
    cout << "\t 2: View All Records\n";
    cout << "\t 3: delete student by id\n";
    cout << "\t 4: delete student by name\n";
    cout << "\t 5: Delete All Records\n";
    cout << "\t 6: Remove Dismissals\n";
    cout << "\t 7: Search Student by id\n";
    cout << "\t 8: Sort Records\n";
    cout << "\t 9: View Number Records\n";
    cout << "\t 9: export Records to File\n";
    cout << "#####################################################\n";

    cout << "Select Operation: ";
}






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
        fprintf(fp, "%-10d %-10s %-20s %-20s %10s %-10.2lf %-20s \n", index, (head->id).c_str(), (head->fname).c_str(), (head->lname).c_str(),(head->sex).c_str(), head->CGPA, (head->status).c_str());
        temp = temp->next;
    }   


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


    fprintf(fp, "%s %s\n", "[new Log", "operation: committed]");
    fprintf(fp, "%-10s %-10s %-20s %-20s %-10s %-10s %-20s\n", "index", "ID No.", "First Name", "Last Name", "Sex", "CGPA","Status");
    fprintf(fp, "%-10d %-10s %-20s %-20s %10s %-10.2lf %-20s \n", index, (head->id).c_str(), (head->fname).c_str(), (head->lname).c_str(),(head->sex).c_str(), head->CGPA, (head->status).c_str());
    
    fclose(fp);
  
}


/**
 * print_data - prints all recods in the database
 * 
 * @head: head pointer of the list
 * Return: returns nothing
 */
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
        
        //printf("%-10ld %-10s %-20s %-20s %-10s %-10.2lf %-20s \n", index, (head->id).c_str(), (head->fname).c_str(), (head->lname).c_str(),(head->sex).c_str(), head->CGPA, (head->status).c_str());
        index++;
        
        temp = temp->next;

    }
    std::cout <<"\n\n";
    return;
}

void print_header()
{

    cout << "\n\n------------------------------------------------------------------------------------------\n";
   // printf("%-10s %-10s %-20s %-20s %-10s %-10s %20s\n", "index", "ID No.", "First Name", "Last Name", "Sex", "CGPA","Status");

    cout << " No\t ID\t First Name\t ";
    cout <<"Last Name \tSex \tCGPA \tStatus\n";
    cout << "-----------------------------------------------------------------------------------------\n";
}



// deleting functions

/**
 * delete_record - deletes function by id or by name
 * @head: pointer to head of the list
 * Return: returns head
 */
student_t *delete_record(student_t *head)
{
	int soption = 0;

	if (head == NULL)
	{
		std::cout << "No Records Available\n";
		return NULL;
	}

	do {
		std::cout << "Select Delete Options\n";
		std::cout << "\t 1: delete by by Id\n";
		std::cout << "\t 2: delete by frist and last name.\n\tThis may cause multiple records to be deleted\n";
		std::cout << "\t 0: to cancel\n ";
		std::cout << "Enter Search Option: ";
		
		std::cin >> soption;
		switch (soption)
		{
			case 0:
				break;
			case 1:
				head = delete_by_id(head);
				break;
			case 2:
				head = delete_by_name(head);
				break;
			default:
				std::cout << "Invalid Choice\n";
				break;
		} 
	}while (soption != 0); 
	
	return head;
	 
}

/**
 * delete_by_id - deletes function by id
 * @head: pointer to head of the list
 * Return: returns head
 */
student_t *delete_by_id(student_t *head)
{
	student_t *current = head, *temp;
	string id;

	temp = new student_t;

	if (head == NULL)
		return NULL;
	
	std::cout << "Enter Id Number of The Student to delete: ";
	std::cin >> id;

	if (current->next == NULL && current->id == id)
	{
		delete(current);
		return NULL;
	}
	while (current->next != NULL && current->id != id)
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


/**
 * delete_by_name - deletes function by name
 * @head: pointer to head of the list
 * Return: returns head
 */
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

	if ((current->next == NULL) && (current->fname == fname && current->lname == lname))
	{
		delete(current);
		return NULL;
	}

	
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

/**
 * free_all_records - deletes all records
 * @head: pointer to head of the list
 * Return: returns head
 */
void free_all_records(student_t **head)
{
	//string status[] = {"Distiniction", "Warning", "Pass", "Dismissal"};
	student_t *temp;
	int fOption = 1;
	
	if ((*head) == NULL)
	{
		std::cout << "No Records at all";
		return ;
	}
  
  	std::cout << "This operation will remove all records\nAre you SURE to remove all? (1 = yes, 0 = No)\nDelete all records? ";
	std::cin >> fOption;
	
	if (fOption == 1)
	{
		while((temp = *head) != NULL)
		{ 
		(*head) = temp->next;
		delete(temp); 
		}
	}
	std::cout << "\n.......All Records Deleted!........\n";
	return ;
}


// remove dismissals

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

    

    
    if (current != NULL)  //(is_empty(current) == false)
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



//searching functions
void search_student(student_t *head)
{
    int soption = 0;

    if (head == NULL)
    {
        std::cout << "No Records Available\n";
        return;
    }

    do {
        std::cout << "Select Options\n";
        std::cout << "\t 1: search by Id\n";
        std::cout << "\t 2: search by frist and last name\n";
        std::cout << "\t 0: to cancel\n ";
        std::cout << "Enter Search Option: ";
        
        std::cin >> soption;
        switch (soption)
        {
            case 0:
                break;
            case 1:
                search_by_id(head);
                break;
            case 2:
                search_by_name(head);
                break;
            default:
                std::cout << "Invalid Choice\n";
                break;
        } 
    }while (soption != 0); 
    
     
    
}


void search_by_name(student_t *head)
{
    student_t *temp;
    size_t index = 0;
    string fname, lname;
    
    std::cout << "Enter the first name: ";
    std::cin >> fname;

    std::cout << "Enter Last Name: ";
    std::cin >> lname;

    
    std::cout << "\n\n==========Search Results==========\n";

    temp = head;
    while (temp != NULL)
    {
        if (temp->fname == fname && temp->lname == lname)
        {
            std::cout << index << "   ";
            std::cout << temp->id << "\t";
            std::cout << temp->fname << "\t";
            std::cout << temp->lname << "\t";
            std::cout << temp->sex << "\t";
            std::cout << temp->CGPA << "\t";
            std::cout << temp->status << "\t\n";
        }
        index++;
        temp = temp->next; 
    }
    std::cout << "\n======================\n";

}
void search_by_id(student_t *head)
{
    student_t *temp;
    size_t index = 0;
    string id;
    
    std::cout << "Enter ID: ";
    std::cin >> id;

    temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            std::cout << "\n\n==========Search Results==========\n";
            std::cout << index << "   ";
            std::cout << temp->id << "\t";
            std::cout << temp->fname << "\t";
            std::cout << temp->lname << "\t";
            std::cout << temp->sex << "\t";
            std::cout << temp->CGPA << "\t";
            std::cout << temp->status << "\t\n";
        }
        index++;
        temp = temp->next; 
    }
    std::cout << "\n======================\n";
}


// sorting records
/**
 * sort_records - sorts records by id or by name
 * 
 * @head: head of the list 
 * Return: returns nothing
 */
student_t *sort_records(student_t *head)
{
    int soption;

    if (head == NULL)
    {
        std::cout << "No Records Available\n";
        return NULL;
    }
    while (soption != 0)
    {
        std::cout << "Select Options\n";
        std::cout << "\t 1: sort by Id\n";
        std::cout << "\t 2: sort by first name\n";
        std::cout << "\t 0: to cancel\n";
        std::cout <<"Enter Sort Option: ";
    
        std::cin >> soption;

        if (soption == 0)
        {
            head = sort_by_id(head);
            std::cout<<"Items sorted by ID\n";

            break;
        }
        else if (soption == 1)
        {
            head = sort_by_name(head);
            std::cout<<"Items sorted by first name\n";
            break;
        }
        else
        {
            std::cout << "Invalid Option \n";
            continue;
        }
           
    }
    return head;
}



student_t *sort_by_id(student_t *head)
{
    student_t *current = head, *left, *right, *sorted;
    int index = 0;
    
    (void)sorted;
    left = new student_t;
    right = new student_t;
    sorted = new student_t;

    if (head == NULL)
    {
        std::cout << "No Records!\n";
        return NULL;
    }

    if (current->next == NULL)
    {
        std::cout << "Only 1 Record in the list\n";
        return head;
    }

    while (current->next != NULL)
    {
        while(current != NULL)
        {
            if(current->id > current->next->id)
            {
                right = current->next;
                left = current;
                // swap_nodes(left, right);

                (void)right;
                (void)left;
                // current->next = left;
                // left->prev = cur
            }
            current = current->next;
        }
        current = current->next;
        index++;
    }

    while (current->prev != NULL)
        current = current->prev;

    std::cout << index;
    return current;
}

student_t *sort_by_name(student_t *head)
{
    string user_id;
    student_t *current = head, *left, *right;

    left = new student_t;
    right = new student_t;

    (void)current;
    (void)left;
    (void)right;
    if (head == NULL)
    {
        std::cout << "No Records!\n";
        return NULL;
    }

    return head;
}
student_t *sort_by_idx(student_t *head)
{
    (void)head;
    return head;
}

void swap_nodes(student_t *node1, student_t *node2)
{
    student_t *temp = new student_t;

    temp = node1;
    node1 = node2;
    node2  = temp;
    node2->next = node1;
    node1->prev = node2;
}