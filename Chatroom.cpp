#include "Chatroom.h"


Fl_Window *chat_window;
Fl_Multiline_Input *send_da_chat;
Fl_Multiline_Output *receive_da_chat;
Fl_Button *send_msg;

vector<string> tot_msgs;


//void send_butt_CB(Fl_Widget *w, void *p)
//{
//	
//}

void clear_send_chat()
{
	send_da_chat->clear_output();
}

void send_msg_CB(Fl_Widget *w, void *p)
{
	string whole_msg;
	cout << "send msg CB" << endl;
	char out[144];
	sprintf(out, "%s", send_da_chat->value());
	string temp;
	temp = out;
	tot_msgs.push_back(temp);
	
	int msg_num = tot_msgs.size();
	cout << "total msgs = " << msg_num << endl;

	int counter = 0;

	while(counter < msg_num)
	{
		whole_msg = whole_msg + "\n" + tot_msgs[counter];
		counter++;

		cout << "total msgs is " << whole_msg << endl;
	}

	strncpy(out, whole_msg.c_str(), sizeof(whole_msg));

	receive_da_chat->value(out);
	//send_da_chat = new Fl_Multiline_Input(50, 450, 900, 400);
	clear_send_chat();
}



Chatroom::Chatroom()
{

}

void Chatroom::run_chatroom()
{
	chat_window = new Fl_Window(1000, 1000, "Public");
	send_da_chat = new Fl_Multiline_Input(50, 450, 900, 400);
	receive_da_chat = new Fl_Multiline_Output(50, 20, 900, 400);

	send_msg = new Fl_Button(800, 850, 100, 100, "Send");
	send_msg->callback((Fl_Callback *)send_msg_CB, 0);
	chat_window->show();
}
