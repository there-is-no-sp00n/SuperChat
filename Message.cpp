#include "Message.h"

Message::Message()
{

}

void Message::set_msg()
{
    cout << "Enter Message: ";
    getline(cin, msg);

    while(msg.length() > 144)
    {
        cout << "ERROR! Message cannot be more than 144 characters" << endl;
        cout << endl;

        cout << "Enter Message: ";
        getline(cin, msg);
    }


}
