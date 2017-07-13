#ifndef SIGN_UP_H
#define SIGN_UP_H

include "User.h"

using namespace std;

Class Sign_Up
{
    public:
            void create_user(User);
            
            void set_user();
            
    private:
            string nick;
            int year;
            string captain;

};

#endif
