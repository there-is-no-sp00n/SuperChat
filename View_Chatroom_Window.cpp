#include "View_Chatroom_Window.h"

Fl_Window* chatroom_win;
Fl_Menu_Bar* menubar;

vector<string> names_of_rooms;//.push_back("Public");

string temp = ("Public");

Chatroom new_chat;


//names_of_rooms.push_back(temp);

const int fixedWidth = 60;
const int defaultHeight = 30;
int num_of_chatrooms = 1;

void NewCB(Fl_Widget* w, void* p)
{
	new_chat.run_chatroom();
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



// Combo widget to appear in the scroll, two boxes: one fixed, the other stretches
class ScrollItem : public Fl_Group {
    Fl_Box *privacyBox;
    Fl_Button *chatroomButton;
public:
    ScrollItem(int X, int Y, int W, int H, const char* L=0) : Fl_Group(X,Y,W,H,L) {
        begin();
            // Fixed width box
            privacyBox = new Fl_Box(X,Y,fixedWidth,defaultHeight,"Public");
            privacyBox->box(FL_UP_BOX);
            // Stretchy box
            chatroomButton = new Fl_Button(X+fixedWidth,Y,W-fixedWidth,defaultHeight, "Public");
            //stretchBox->box(FL_UP_BOX);
            resizable(chatroomButton);
        end();
    }
};

// Custom scroll that tells children to follow scroll's width when resized
class MyScroll : public Fl_Scroll {
    int nchild;
public:
    MyScroll(int X, int Y, int W, int H, const char* L=0) : Fl_Scroll(X,Y,W,H,L) {
        nchild = 0;
    }
    void resize(int X, int Y, int W, int H) {
        // Tell children to resize to our new width
        for ( int t=0; t<nchild; t++ ) {
            Fl_Widget *w = child(t);
            w->resize(w->x(), w->y(), W-20, w->h());    // W-20: leave room for scrollbar
        }
        // Tell scroll children changed in size
        init_sizes();
        Fl_Scroll::resize(X,Y,W,H);
    }
    
    // Append new scrollitem to bottom
    //     Note: An Fl_Pack would be a good way to do this, too
    //
    void AddItem() {
        int X = x() + 1,
            Y = y() - yposition() + (nchild*defaultHeight) + 1,
            W = w() - 20,                           // -20: compensate for vscroll bar
            H = defaultHeight;
        add(new ScrollItem(X,Y,W,H));
        redraw();
        nchild++;
    }
};

// Callback to add new item to scroll
void add_cb(Fl_Widget*, void *data) 
{
	num_of_chatrooms ++;
	if(num_of_chatrooms <= 10)
	{
		MyScroll *scroll = (MyScroll*)data;
		scroll->AddItem();
	}
}



void View_Chatroom_Window::show_the_rooms()
{
	
	Fl_Double_Window *chatroom_win = new Fl_Double_Window(500,300, "Chatrooms");
   	 //win->color(FL_WHITE);
   	 MyScroll *scroll = new MyScroll(10,50,chatroom_win->w()-20,chatroom_win->h()-100);
   	 scroll->box(FL_BORDER_BOX);
   	 scroll->end();
   	 menubar = new Fl_Menu_Bar(0, 0, 500, 30);
   	 menubar->menu(menuitems);
	
   	 Fl_Button *add_butt = new Fl_Button(chatroom_win->w()-150, chatroom_win->h()-40, 100, 25, "Add");
   	 add_butt->callback(add_cb, (void*)scroll);
   	  //Create a few widgets to start with
   	 for ( int t=0; t<1; t++ )
	{
		scroll->AddItem();
	}
    chatroom_win->resizable(scroll);
    chatroom_win->show();
}
