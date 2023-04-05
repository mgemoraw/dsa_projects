#include "student.h"

extern size_t numberOfStudents;


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
