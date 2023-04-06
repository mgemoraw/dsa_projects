#include "towns.h"

/**
 * print_data - prints all recods in the database
 * 
 * @head: head pointer of the list
 * Return: returns nothing
 */
void print_records(town_t **head)
{
    size_t index = 1;

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
        printf("%-5ld %-10s %-20s %-10s %-10s %10.3lf %10.3lf \n", index, (temp->id).c_str(), (temp->name).c_str(), (temp->latitude).c_str(), (temp->longitude).c_str(), temp->dist_from_bdr, temp->dist_from_aa);
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

