#include "towns.h"

extern size_t town_number;
/**
 * delete_record - deletes function by id or by name
 * @head: pointer to head of the list
 * Return: returns head
 */
void delete_record(town_t **head)
{
	int doption = 0;

	if (*head == NULL)
	{
		cout << "No Records Available\n";
		return ;
	}

	do {
		cout << "Select Delete Options\n";
		cout << "\t 1: delete by by Id\n";
		cout << "\t 2: delete by name of the town\n\t";
		cout << "\t 0: to cancel\n ";
		cout << "Enter delete Option: ";
		
		cin >> doption;
        cin.ignore(256, '\n'); // remove buffer text
    
		switch (doption)
		{
			case 0:
				break;
			case 1:
				delete_by_id(head);
				break;
			case 2:
				delete_by_name(head);
				break;
			default:
				cout << "Invalid Choice\n";
				break;
		} 
	}while (doption != 0); 
	
	return;
	 
}

/**
 * delete_by_id - deletes function by id
 * @head: pointer to head of the list
 * Return: returns head
 */
void delete_by_id(town_t **head)
{
	town_t *current = *head, *temp;
	string id, town_name;

	temp = new town_t;

	if (*head == NULL)
		return ;
	
	
	// enter id of town to be deleted
	cout << "Enter Town ID: ";
	getline(cin, id);

	if (current->next == NULL && current->id == id)
	{
		town_name = current->name;
		delete(current);
		return ;
	}
	while (current->next != NULL && current->id != id)
		current = current->next;

	// name of town to be deleted
	town_name = current->name;

	// prevent head and tail from deletion
	if (current->prev == NULL || current->next == NULL)
	{
		cout << "\n .................Delete Failed....................\n";
		cout << "Quotion! Can't delete the Start/End Towns Only Delete in Between!\n";
		cout << "Add town in between the two cities first\n";
		cout << "................ Thanks for using our product ........\n";
		return;
	}

	

	temp = current->prev;
	temp->next = current->next;

	while (temp->prev != NULL)
	{
		temp = temp->prev;
	}

	*head = temp;
	delete(current);
	town_number--;

	cout << "\n..................Delete Success!....................\n";
	cout << "Deleted Town:.................... " << town_name << "...\n"; 
	cout << "................ Thanks for using our product ........\n";
	return;
}


/**
 * delete_by_name - deletes function by name
 * @head: pointer to head of the list
 * Return: returns head
 */
void delete_by_name(town_t **head)
{
	town_t *current = *head, *temp;
	string name;
	

	temp = new town_t;

	if (*head == NULL)
		return ;
	
	

	// enter name of town to be deleted
	cout << "Enter Town Name: ";
	getline(cin, name);
	

	// if ((current->next == NULL) && (current->name == name))
	// {
	// 	delete(current);
	// 	return ;
	// }


	
	while (current->name != name) 
		current = current->next;

	// prevent head and tail from deletion
	if (current->prev == NULL || current->next == NULL)
	{
		cout << "\n..................Delete Failed!....................\n";
		cout << "Quotion! Can't delete the Start/End Towns Only Delete in Between!\n";
		cout << "Add town in between the two cities first\n";
		cout << "................ Thanks for using our product ........\n";
		return;
	}
	
	temp = current->prev;
	temp->next = current->next;

	while (temp->prev != NULL)
	{
		temp = temp->prev;
	}

	*head = temp;
	delete(current);
	town_number--;

	cout << "\n..................Delete Success!....................\n";
	cout << "Deleted Town:.................... " << name << "...\n"; 
	cout << "................ Thanks for using our product ........\n";
	return;
}

/**
 * free_all_records - deletes all records
 * @head: pointer to head of the list
 * Return: returns head
 */
void free_all_records(town_t **head)
{
	town_t *temp;
	int fOption = 1;
	
	if ((*head) == NULL)
	{
		cout << "No Records at all";
		return ;
	}
  
  	cout << "This operation will remove all records\nAre you SURE to remove all? (1 = yes, 0 = No)\nDelete all records? ";
	cin >> fOption;
	
	if (fOption == 1)
	{
		while((temp = *head) != NULL)
		{ 
		(*head) = temp->next;
		delete(temp); 
		}
	}
	cout << "\n.......All Records Deleted!........\n";
	return ;
}

