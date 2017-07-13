#ifndef USER_H
#define USER_H

#include Message.h

class User
{
    public:
          User()
          
          
          void set_user();
    
          void create_msg();
    
          void send_message(Message);


    private:
    
          string nick;
          string UUID;
          string captain;
          bool online;
          vector <user> ban_list;
          
}

#endif
