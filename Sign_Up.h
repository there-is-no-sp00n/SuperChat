#ifndef SIGN_UP_H
#define SIGN_UP_H

#include "User.h"

using namespace std;

class Sign_Up
{
    public:
            Sign_Up();

            void create_user();

            void set_user();

    private:
            string allowed_captains[4] = {"Kirk", "Picard", "Pike", "Other"};
            string nick;
            int year;
            string captain;

};

#endif
