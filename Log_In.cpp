#include "Log_In.h"

Fl_Window *log_screen;
Fl_Window *success_win;
Fl_Window *unsuc_win;

Fl_Text_Display *log_msg;

Fl_Input *name;
Fl_Output *cap_val;
Fl_Scrollbar *cap_scroll;
Fl_Button *log_in_enter;
Fl_Button *log_ok;


string logged_in_user;

int user_capi;
string allowed_captain[4] = {"kirk", "picard", "pike", "other"};

vector<User> log_vec;

void success_CB(Fl_Widget *w, void *p)
{
	success_win->hide();
}

void log_scroll_CB(Fl_Widget *w, void *p)
{
	char s[20];
	sprintf(s, "%d", cap_scroll->value());
	cap_val->value(s);

	string u = s;
	user_capi = atoi(u.c_str());
}



void log_in_enter_CB()
{
	string nick, cap, nick_1, cap_1;
	
	cap = allowed_captain[user_capi-1];
	int flag = 0;
	User temp;


	nick = name->value();
	
	
	int vec_s = log_vec.size();
	
	cout << "log vec size = " << vec_s << endl;

	cout << temp.get_nick(temp).compare(nick) << endl;

	for(int i = 0; i < vec_s; i++)
	{
		temp = log_vec[i];
		nick_1 = temp.get_nick(temp);
		cap_1 = temp.get_captain(temp);
		cout << "login i = " << i << endl;
		if((nick_1 == nick))
		{
			cout << "1login i = " << i << endl;
			if(cap == cap_1)
			{
				cout << "2login i = " << i << endl;
				flag = 1;
				success_win = new Fl_Window(320, 200);
				log_msg = new Fl_Text_Display(150,100,0,0, "Log In Success!");
				log_ok = new Fl_Button(175, 150, 30, 25, "OK");
				log_ok->callback((Fl_Callback*)success_CB,0);
				success_win->show();
				success_win->color(FL_RED);
				logged_in_user = nick_1;
				log_screen->hide();
				break;
			}		
		}	
	}

	if(flag == 0)
	{
		success_win = new Fl_Window(320, 200);
		log_msg = new Fl_Text_Display(150,100,0,0, "Log In Failure");
		log_ok = new Fl_Button(175, 150, 30, 25, "OK");
		log_ok->callback((Fl_Callback*)success_CB,0);
		success_win->show();
		success_win->color(FL_RED);
	}

}

void from_da_file()
{
	ifstream to_vec;
	to_vec.open("File_User.txt");
	
	int counter = 0;

    	string name, captain, UUID_s, year_s;
    	int UUID, year;

	cout << "from file at opening log_in" << endl;
	

    	while(to_vec >> UUID_s >> name >> year_s >> captain)
    	{
        	if(counter > 0)
        	{
            		UUID = stoi(UUID_s);
            		year = stoi(year_s);

            		User temp(name, UUID, year, captain);
            
	    		log_vec.push_back(temp);
        	}

        	counter++;

    	}

    to_vec.close();

	int vec_siz = log_vec.size();

	for(int i = 0; i < vec_siz; i++)
	{
		User temp = log_vec[i];
		
		cout << temp.get_UUID(temp) << endl;
		cout << temp.get_nick(temp) << endl;
		cout << temp.get_grad_year(temp) << endl;
		cout << temp.get_captain(temp) << endl;
	}

}


void Log_In::log_s()
{
	from_da_file();
	log_screen = new Fl_Window(500, 500, "Log In");
	log_screen->color(FL_YELLOW);

	name = new Fl_Input(120, 10, 210, 25, "Nick");
	
	cap_scroll = new Fl_Scrollbar(50, 150, 50, 50);
	cap_scroll->bounds(1,4);
	cap_scroll->step(1);
	cap_scroll->callback(log_scroll_CB, (void*)&cap_val);

	cap_val = new Fl_Output(120, 100, 210, 25, "Captain");
	cap_val->textsize(24);

	log_in_enter = new Fl_Button(200, 200, 50, 50, "Enter");
	log_in_enter->callback((Fl_Callback*)log_in_enter_CB, 0);

	log_screen->end();
	log_screen->set_non_modal();
	log_screen->show();

}

string Log_In::get_logged_in_user()
{
	return logged_in_user;
}
