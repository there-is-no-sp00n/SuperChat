#include "Controller.h"

Controller::Controller()
{

}

void Controller::run_the_show()
{
    User def_user;

    ifstream file;

    file.open("File_User.txt");


    //checking to see if the file is empty or not AKA is there a user already created?
    if(file.peek() == std::ifstream::traits_type::eof())
    {
        //if file empty go into sign up screen
        Sign_Up test;
        test.set_user();
        test.create_user();

        file.close();
    }

    else
    {
        //log in screen
        Log_In log_in_t;
        log_in_t.set_default_user();

        def_user = log_in_t.get_user();

        cout << def_user.get_nick(def_user) << endl;
        cout << def_user.get_grad_year(def_user) << endl;
        cout << def_user.get_captain(def_user) << endl;
        cout << def_user.get_UUID(def_user) << endl;

        file.close();
    }



    //Message m_test;

    //m_test.set_msg("john", 434343, 1);

}
