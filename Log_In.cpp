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

Fl_Button *change_nick;
Fl_Window *change_nick_win;
Fl_Input *change_nick_input;
Fl_Input *change_nick_input_1;
Fl_Button *enter_change_nick;

string nick_to_be_changed;
string da_new_nick;


string logged_in_user;

int user_capi;
string allowed_captain[4] = {"kirk", "picard", "pike", "other"};

vector<User> log_vec;


void to_da_file(vector<User> user_l)
{
	ofstream user_file;
	user_file.open("File_User.txt");
    	user_file << "UUID"  << " " << setw(25) << "Nick" << " " << setw(20) << "Year" << " " << setw(20) << "Captain" << endl;
    	user_file << endl;
	int use_s = user_l.size();

	cout << "print vector size" << use_s << endl;

	for(int i = 0; i < use_s; i++)
	{
		cout << "i = " << i << endl;
		User temp;

		//int UUID, year;
		//string name, captain;

		temp = user_l[i];
		//UUID = temp.get_UUID(temp)

		user_file << temp.get_UUID(temp) << " " << setw(20) << temp.get_nick(temp) << " " << setw(20) << temp.get_grad_year(temp) << " " << setw(20) << temp.get_captain(temp) << endl;

	}
	user_file.close();
    		
}



void ok_change_name_CB(Fl_Widget *w, void *p)
{

	User temp;

	int flag = 1;


	string old_nick = change_nick_input->value();
	string new_nick = change_nick_input_1->value();
	
	cout << "new nick2 " << new_nick << endl;
		cout << "old nick2 " << old_nick << endl;
	
	int vec_s = log_vec.size();
	
	cout << "log vec size = " << vec_s << endl;

	//cout << temp.get_nick(temp).compare(nick) << endl;

	for(int i = 0; i < vec_s; i++)
	{
		temp = log_vec[i];	
		cout << "new nick " << new_nick << endl;
		cout << "old nick " << old_nick << endl;
		string nick_1 = temp.get_nick(temp);
		cout << "vec_nick " << nick_1 << endl;
		if(old_nick == nick_1)
		{
			flag = 0;
			log_vec[i].set_nick(new_nick);
			change_nick_win->hide();
			to_da_file(log_vec);
			break;
		}
		
		
	}

	if(flag == 1)
	{
		fl_message("The nick does not exist");
	}

	for(int i = 0; i < vec_s; i++)
	{
		User temp = log_vec[i];
		
		cout << temp.get_UUID(temp) << endl;
		cout << temp.get_nick(temp) << endl;
		cout << temp.get_grad_year(temp) << endl;
		cout << temp.get_captain(temp) << endl;
	}


}

void change_nick_CB(Fl_Widget *w, void *p)
{
	log_screen->hide();
	cout << "rename nick" << endl;
	change_nick_win = new Fl_Window(500, 500, "Change Log-In");

	change_nick_input = new Fl_Input(150, 50, 100, 100, "Old Nick");
	change_nick_input_1 = new Fl_Input(150, 175, 100, 100, "New Nick");

	enter_change_nick = new Fl_Button(300,300, 50, 50, "OK");
	enter_change_nick->callback((Fl_Callback*)ok_change_name_CB, 0);
	
	change_nick_win->resizable(change_nick_win);
	change_nick_win->show();
	
}

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

	change_nick = new Fl_Button(300,300, 50, 50, "Change");
	change_nick->callback((Fl_Callback*)change_nick_CB, 0);

	log_screen->end();
	log_screen->set_non_modal();
	log_screen->show();

}

string Log_In::get_logged_in_user()
{
	return logged_in_user;
}
