#ifndef USER_H
#define USER_H

#include <vector>
#include "Message.h"

using namespace std;

class User
{
    public:
          User();


          void set_user();

          void create_msg();

          void send_message(Message);


    private:

          string nick;
          string UUID;
          string captain;
          bool online;
          vector <User> ban_list;

};

#endif
