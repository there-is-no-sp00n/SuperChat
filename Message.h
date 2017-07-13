#ifndef MESSAGE_H
#define MESSAGE_H

class Message
{
    public:
    
          Message();
          
          void set_msg();

    private:
    
          string user;
          string UUID;
          string msg;
          
          bool prv_msg;
          
}
