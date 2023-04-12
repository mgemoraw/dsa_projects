#include "towns.h"

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