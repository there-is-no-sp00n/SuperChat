#include "Sign_Up.h"


Sign_Up::Sign_Up()
{

}

void Sign_Up::set_user()
{
    cout << "What is your nick? ";
    getline(cin, nick);
    cout << endl;


    while(nick.length() > 8)
    {
        cout << "ERROR! The nick must be at most 8 characters." << endl;
        cout << "What is your nick? ";
        getline(cin, nick);
        cout << endl;
    }

    //have to refine this statement to not take double quotes ""
    while (nick.find_first_of("1234567890!@#$%^&*.?;:,+'/}{]" "[><~` ") != string::npos)
    {
        cout << "ERROR! Only Upper & Lower case letters allowed and '-' or '_'" << endl;
        cout << "What is your nick? ";
        getline(cin, nick);
        cout << endl;
    }


    cout << "What is your expected year of graduation? ";
    cin >> year;
    cout << endl;

    while (year >= 2040 && year <= 2017)
    {
        cout << "ERROR! Year of graduation must be between 2017 and 2040" << endl;

        cout << "What is your expected year of graduation? ";
        cin >> year;
        cout << endl;
    }

    cout << "Choose from the following Enterprise Captains" << endl;

    cout << "Press 1 for " << allowed_captains[0] << endl;
    cout << "Press 2 for " << allowed_captains[1] << endl;
    cout << "Press 3 for " << allowed_captains[2] << endl;
    cout << "Press 4 for " << allowed_captains[3] << endl;

    int choice;

    cin >> choice;

    while(choice < 1 || choice > 4)
    {
        cout << "ERROR! Choice must be between these captains" << endl;

        cout << "Press 1 for " << allowed_captains[0] << endl;
        cout << "Press 2 for " << allowed_captains[1] << endl;
        cout << "Press 3 for " << allowed_captains[2] << endl;
        cout << "Press 4 for " << allowed_captains[3] << endl;

        cin >> choice;

        captain = allowed_captains[choice - 1];

    }

}

void Sign_Up::create_user()
{
    User new_user;

    new_user.set_user(nick, year, captain);
}
