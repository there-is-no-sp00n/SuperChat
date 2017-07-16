#include "Chatroom.h"

Chatroom::Chatroom()
{

}

void Chatroom::create_chatroom()
{
    cout << "What is the name of the chatroom? ";
    getline(cin, room_name);
    cout << endl;


    while(room_name.length() > 8)
    {
        cout << "ERROR! The Chatroom name must be at most 8 characters." << endl;
        cout << "What is the name of the chatroom ";
        getline(cin, room_name);
        cout << endl;
    }




}
