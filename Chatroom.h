#ifndef CHATROOM_H
#define CHATROOM_H

#include "Message.h"
#include "User.h"

using namespace std;

class Chatroom
{
    public:
            Chatroom();

            void create_chatroom();

            void disp_msg(vector <Message>);

            void put_msg_in_vec(Message);

            void disp_chat_user(vector <User>);

    private:
             vector <Message> the_msg;

             vector <User> the_users;

             string room_name;

             int room_index;


};

#endif
