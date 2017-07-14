#ifndef USER_H
#define USER_H

#include <vector>
#include "Message.h"

using namespace std;

class User
{
    public:
          User();


          void set_user(string, int, string);

          void create_msg();

          void send_message(Message);

          void make_offline();


    private:

          string nick;
          string UUID;
          int year;
          string captain;
          //bool online;
          vector <User> ban_list;

};

#endif
