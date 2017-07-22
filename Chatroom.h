#ifndef CHATROOM_H
#define CHATROOM_H

#include "Message.h"
#include "User.h"

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Multiline_Output.H>

#include <vector>

using namespace std;

class Chatroom
{
    public:
            Chatroom();

            void run_chatroom();

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
