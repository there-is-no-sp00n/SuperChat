#ifndef LOG_IN_H
#define LOG_IN_H

#include <fstream>
#include <string>
#include "User.h"

class Log_In
{
    public:
        Log_In();

        void set_default_user();

        User get_user();

    private:

        User default_user;

        ifstream from_file;

};

#endif
