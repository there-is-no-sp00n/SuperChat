#include "Controller.h"

Controller::Controller()
{

}

void Controller::run_the_show()
{
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

        file.close();
    }



    //Message m_test;

    //m_test.set_msg("john", 434343, 1);

}
