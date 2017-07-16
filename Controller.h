#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <fstream>
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>



#include "Sign_Up.h"
#include "Log_In.h"
#include "Message.h"

#include "Create_User_Dialog.h"


class Controller
{
    public:
        Controller();

        int run_the_show();
	
	//void to_file(vector<User>);

};

#endif // CONTROLLER_H
