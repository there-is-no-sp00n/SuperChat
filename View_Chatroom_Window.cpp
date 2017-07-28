#include "View_Chatroom_Window.h"

Fl_Window* chatroom_win;
Fl_Menu_Bar* menubar;


Fl_Window* name_da_room;
Fl_Input* chatroom_name_inp;
Fl_Button* chat_name_butt;

Fl_Box *privacy_box;
Fl_Button *chatroomButton;

Fl_Button *add_room;

Fl_Browser *browser;
Fl_Input_Choice *choi;

struct chatrooms_available
{
	Fl_Button *chat_name;
	Fl_Box *chat_index;
};

int num_of_chatrooms = 1;

vector<struct chatrooms_available> toto_rooms;


char chat_r_name[25] = "Public";
char const *chat_ind;

vector<string> nono_roro;

Chatroom new_chat;

void chat_butt_CB(Fl_Widget *w, void *p)
{
	string temp;

	temp = choi->value();
	
	cout << "chosen room is " << temp << endl;

	new_chat.run_chatroom(temp);
}

void view_room_CB(Fl_Widget *w, void *p)
{
	Fl_Window *chatroom_win = new Fl_Double_Window(1000,1000, "Chatrooms");

	choi = new Fl_Input_Choice(100,100,100,100,"rooms");
	choi->add("Public");
	int toto_size = toto_rooms.size();
	for(int i = 0; i <toto_size; i++)
	{
		cout << "size of toto_rooms " << toto_rooms.size() << endl;
		cout << "name of room " << nono_roro[i] << endl;

		strncpy(chat_r_name, nono_roro[i].c_str(), sizeof(nono_roro[i]));
		
		choi->add(chat_r_name);

	}
	
	Fl_Button *create_chat_room = new Fl_Button(300,300,50,50,"Open");
	create_chat_room->callback((Fl_Callback *)chat_butt_CB);


    chatroom_win->show();
	
}




//const int fixedWidth = 60;
//const int defaultHeight = 30;


void enter_chat_name_CB(Fl_Widget *w, void *p)
{
	string c_n;
	
	int siz = toto_rooms.size();
	
	c_n = chatroom_name_inp->value();
	nono_roro.push_back(c_n);
	strncpy(chat_r_name, c_n.c_str(), sizeof(c_n));
	
	string s = to_string(siz-1);
	chat_ind = s.c_str();	

	struct chatrooms_available temp;
	temp.chat_name = new Fl_Button(100, siz-1 * 50, 200, siz-1 * 50, chat_r_name);
	temp.chat_index = new Fl_Box(50, siz-1 * 50, 50, siz-1 * 50, chat_ind);
	toto_rooms.push_back(temp);
	
	//strncpy(chat_type, c_t.c_str(), sizeof(c_t));
	name_da_room->hide();
	
}

void NewCB(Fl_Widget* w, void* p)
{
	num_of_chatrooms++;
	
	
	if(num_of_chatrooms > 10)
	{
		cout << "num of rooms " << num_of_chatrooms << endl;
		fl_message("Cannot have more than 10 chatrooms");
	}

	else
	{
		cout << "num of rooms " << num_of_chatrooms << endl;
		name_da_room = new Fl_Window(400, 400, "New Room");
		chatroom_name_inp = new Fl_Input(100, 100, 200, 200, "Name");
		chat_name_butt = new Fl_Button(200, 200, 50, 50, "Enter");
		chat_name_butt->callback((Fl_Callback *)enter_chat_name_CB, 0);
		name_da_room->show();
	}
	
}


void delete_chatroomCB(Fl_Widget* w, void* p)
{

}

void display_usersCB(Fl_Widget* w, void* p)
{

}

void change_nicknameCB(Fl_Widget* w, void* p)
{
  
}

void ExitCB(Fl_Widget* w, void* p)
{
  chatroom_win->hide();
}


Fl_Menu_Item menuitems[] = {
  {"&Chatroom", 0,0,0, FL_SUBMENU},
    {"Create Chatroom", 0, (Fl_Callback*)NewCB},
    {"Delete Chatroom", 0, (Fl_Callback*)delete_chatroomCB},
    {0},
  {"&Users", 0,0, 0, FL_SUBMENU},
    {"List Users", 0, (Fl_Callback *)display_usersCB},
    {0},
  //{"&Setting", 0,0,0, FL_SUBMENU},
  //  {"Change Nickname", 0, (Fl_Callback *)change_nicknameCB},
  //  {"Exit", 0, (Fl_Callback *)ExitCB},
  //  {0},
  {0}
};


void View_Chatroom_Window::update_the_vec(string da_name)
{

}



void View_Chatroom_Window::show_the_rooms()
{
	Fl_Window *chatroom_win = new Fl_Double_Window(500,500, "Chatrooms");
	chat_name_butt = new Fl_Button(100, 50, 200, 50, "View");
	chat_name_butt->callback((Fl_Callback *)view_room_CB);
	
   	menubar = new Fl_Menu_Bar(0, 0, 500, 30);
   	menubar->menu(menuitems);

	chatroom_win->resizable(chatroom_win);
	chatroom_win->show();
}
