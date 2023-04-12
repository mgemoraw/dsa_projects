#include "towns.h"

size_t town_number = 2;

town_t *head, *tail;
/**
* main - main function
*
*/
int main(void)
{
    //town_t *head = NULL, *tail;
    int op = 2;

    head = new town_t;
    tail = new town_t;

    head->index = 0;
    head->id = "ET6000";
    head->name = "Bahir Dar";
    head->description = "Bahir Dar is the capital of regional government of Amhara national regional state";
    head->dist_from_bdr = 0;
    head->dist_from_aa = 565;
    head->latitude = "11.5742° N";
    head->longitude = "37.3614° E";
    head->next = tail;
    head->prev = NULL;


    tail->index = 1;
    tail->id = "ET1000";
    tail->name = "Addis Ababa";
    tail->description = "Addis Ababa is the Capital City of Ethiopia";
    tail->dist_from_bdr = 565;
    tail->dist_from_aa = 0;
    tail->latitude = "11.5742° N";
    tail->longitude = "37.3614° E";
    tail->next = NULL;
    tail->prev = head;


  
    // cout << format();
    do {

        print_menu();
        cin >> op;

        cin.ignore(256, '\n');

        switch(op)
        {
            case 0:
                cout << "\n......exiting from system........\n";
                break;
            case 1:
                add_town(&head);
                break;
            case 2:
                print_records(&head);
                break;
            case 3:
                delete_record(&head);
                break;
            case 4:
                search_town(head);
                break;
            case 5:
                origin_dest(&head);
                break;
            default:
                cout << "Invalid Choice. Please Try again ";
                break;
        }
    } while (op != 0);
    return (0);
}


/**
 * add_record - calls add_student function every time when adding record is requested
 * 
 * @param head 
 * @return head
 */
void add_town(town_t **head)
{
    int aOption = 1;

    add_new_town(head);

    while (aOption != 0)
    {
        cout << "\nAdd Another Record (yes = 1, No = 0)? \n";
        cin >> aOption;
        cin.ignore(256, '\n');

        if (aOption == 1)
        {
            add_new_town(head);
            continue;
        }
        else
            break;
        
    }
    
    return; 
}

/**
 * add_student - adds student to the database
 * 
 * @head: head of the list 
 * Return: returns head of the list after addition 
 */
void add_new_town(town_t **head)
{
    town_t *node = new town_t;
    town_t *temp = *head, *temp2;
    // char new_line;
    

    cout << "Enter Town Information\n";
    cout << "Enter Unique Town id: ";
    // new_line = cin.get();
    getline(cin, node->id); //getline(cin >> ws, name);

    cout << "Enter Town Name: ";
    getline(cin, node->name);

    // getchar();

    cout << "Enter Description ";
    getline(cin, node->description);

    cout << "Enter Longitude: ";
    getline(cin, node->longitude);
    
    // getchar();

    cout << "Enter Latitude: ";
    getline(cin, node->latitude);

    // getchar();
    cout << "Enter distance from Bahir Dar(km): ";
    cin >> node->dist_from_bdr;

    //distance from aa = 565 - distance from bdr
    node->dist_from_aa = 565.00 - node->dist_from_bdr;

    cin.ignore(256, '\n');

    
    
    node->prev = NULL;
    node->next = NULL;


    if (*head == NULL)
    {
        *head = node;
        return;
    }

    while (temp->prev != NULL)
        temp = temp->prev;
    
    if (temp->next == NULL && temp->dist_from_bdr < node->dist_from_bdr)
    {
        node->index = 0;
        node->next = temp;
        temp->prev = node;
        temp->index += 1 ;
        *head = node;
        return;
    }
    else
    {
        while (temp->dist_from_bdr < node->dist_from_bdr)
        {
            temp = temp->next;
        }
        
        node->index = temp->index - 1;

        // This adds a town before a town
        temp2 = temp->prev;
        temp2->next = node;
        node->next = temp;
        node->prev = temp2;
        temp->prev = node;
        

        //This adds town after current town;
        /*
        // temp2 = new town_t;
        temp2 = temp->next;
        temp->next = node;
        // temp2->prev = node;
        node->next = temp2;
        node->prev = temp;
        */

    }
   

   
    while (temp->prev != NULL)
        temp = temp->prev;

    *head = temp;

    town_number++;
    // write_log(node);

    return;
}


// delete operations

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



/**
 * print_data - prints all recods in the database
 * 
 * @head: head pointer of the list
 * Return: returns nothing
 */
void print_records(town_t **head)
{
    unsigned long int index = 1;

    if (head == NULL)
    {
        cout << "Database Empty!\n";
        return;
    }
    // double dist_from_aa = 0;
    // double dist_from_bdr = 0;

    town_t *temp = *head;

    print_header();

    while (temp != NULL)
    {
        /*
        cout << index << "   ";
        cout << temp->id << "\t";
        cout << temp->fname << "\t";
        cout << temp->lname << "\t";
        cout << temp->sex << "\t";
        cout << temp->CGPA << "\t";
        cout << temp->status << "\t\n";
        */
        printf("%-5lu %-10s %-20s %-10s %-10s %10.3lf %10.3lf \n", index, (temp->id).c_str(), (temp->name).c_str(), (temp->latitude).c_str(), (temp->longitude).c_str(), temp->dist_from_bdr, temp->dist_from_aa);
        index++;
        
        temp = temp->next;

    }
    cout <<"\n\n";
    return;
}

void print_header()
{

    cout << "\n\n----------------------------------------------------------------------\n";
    // cout << " No\t ID\t First Name\t ";
    // cout <<"Last Name \tSex \tCGPA \tStatus\n";
    printf("%-5s %-10s %-20s %-10s %-10s %-15s %-15s \n", "index", "Town ID", "Town Name", "Latitude", "Longitude", "Dist. From Bdr", "Dist. From AA");
    
    cout << "----------------------------------------------------------------------\n";
}

void search_town(town_t *head)
{
    int soption = 0;
    town_t *town;

   do {
    cout << "\n##### Search Options: \n";
    cout << "\t 0: Cancel search\n";
    cout << "\t 1: Search by Town ID\n";
    cout << "\t 2: Search by Town Name\n";
    cout << "## Enter Option: ";

    cin >> soption;
    cin.ignore(256, '\n');


    switch(soption) {
        case 0:
            break;
        case 1:
            town = search_by_id(head);
            display_town_info(town);
            break;
        case 2:
            town = search_by_name(head);
            display_town_info(town);
            break;
        default:
            cout << "\n !Invalid Option. \nselect search Option: ";
            break;
    }

   } while (soption != 0);

}

town_t *search_by_id(town_t *head)
{
    string town_id;

    town_t *town = head;


    cout << "Enter Town ID: ";

    getline(cin, town_id);


    while (town !=NULL && (town->id != town->id))
    {
        town = town->next;
    }

    return town;
}
town_t *search_by_name(town_t *head)
{
    string town_name ;
    town_t *town = head;

    cout << "Enter Town Name: ";
    getline(cin, town_name);


    while (town != NULL)
    {
        if ((town->name).c_str() == town_name)
            break;
        town = town->next;
    }

    return town;
}
void display_town_info(town_t *town)
{
    double dist_from_prev = 0, dist_to_next = 0;
    string prev_town, next_town;

    //calculate distance from previous town

    dist_from_prev = (town->prev != NULL) ? (town->dist_from_bdr - town->prev->dist_from_bdr) : 0.0;

    // calculate distance to next town
    dist_to_next = (town->next != NULL) ? ( -(town->dist_from_bdr) + town->next->dist_from_bdr): 0;

    
    prev_town = (town->prev != NULL) ? town->prev->name : "Bahir Dar";
    next_town = (town->next != NULL) ? town->next->name : "Addis Ababa";


    if (town)
    {
        

        cout << "\n========================== Search Results ===================================\n";
        cout <<"\nTown Name: ................" <<town->name << "\n";
        cout << "Town ID: ..................." << town->id << "\n";
        cout << "Description: ..............." << town->description << "\n";
        cout << "Latitude: .................." << town->latitude << "\n";
        cout << "Longitude: ................." << town->longitude << "\n";
        cout << "Distance From Bahir Dar: ..." << town->dist_from_bdr << " km\n";
        cout << "Distance From Addis Ababa: .." << town->dist_from_aa << " km\n";

        cout <<town->name  << " is " << dist_from_prev << "km(s) far from " <<  prev_town << ".\n";
        cout <<town->name  << " is " << dist_to_next << "km(s) far from " <<  next_town << ".\n";

        // cout << "Next Town: .................." << next_town << "..." << dist_to_next << " km \n";
        cout << "\n=====================================================================\n";
    }
    else 
    {
        
        cout << "\n---------No Records Found---------------\n";
        return;
    }
}



// origin -destination 

void origin_dest(town_t **head)
{
    
    town_t *o_town, *d_town;
    string origin, dest;

    double distance = 0.0;

    cout << "\nEnter Origin Town name: ";
    getline(cin, origin);

    cout << "\nEnter Destination Town name: ";
    getline(cin, dest);

    o_town = search_by_name(*head, origin);
    d_town = search_by_name(*head, dest);

    if (o_town == NULL)
    {
        cout << "\n......Origin Town not found.....\n";
        return;
    }
    
    if (d_town == NULL)
    {
        cout << "\n......Destination Town not found.....\n";
        return;
    }

    distance = o_town->dist_from_bdr - d_town->dist_from_bdr;

    if (distance < 0)
        distance = -distance;


    cout << "\n========================== O-D Results=================================\n";
    cout <<"\nOrition Town: ............." <<origin << "\n";
    cout << "Destination Town: .........." << dest << "\n";
    cout << "Distance Between: .........." << distance << "\n";
    cout << "\n=====================================================================\n";

return ;
}


town_t *search_by_name(town_t *head, string town_name)
{
    // string town_name ;
    town_t *town = head;

    // cout << "Enter Town Name: ";
    // getline(cin, town_name);


    while (town != NULL)
    {
        if ((town->name).c_str() == town_name)
            break;
        town = town->next;
    }

    return town;
}


// utils

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


