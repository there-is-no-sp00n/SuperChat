#include "Controller.h"

Fl_Window *win;

Fl_Button *rp_sign_up;
Fl_Button *close_main;

Create_User_Dialog sign_up_screen;

vector<User> list_da_users, from_other;

void to_file(vector<User> user_l)
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


void from_file()
{
	ifstream to_vec;
	to_vec.open("File_User.txt");
	
	int counter = 0;

    	string name, captain, UUID_s, year_s;
    	int UUID, year;

	cout << "from file at opening" << endl;
	

    	while(to_vec >> UUID_s >> name >> year_s >> captain)
    	{
        	if(counter > 0)
        	{
            		UUID = stoi(UUID_s);
            		year = stoi(year_s);

            		User temp(name, UUID, year, captain);
            
	    		list_da_users.push_back(temp);
        	}

        	counter++;

    	}

    to_vec.close();

	int vec_siz = list_da_users.size();

	for(int i = 0; i < vec_siz; i++)
	{
		User temp = list_da_users[i];
		
		cout << temp.get_UUID(temp) << endl;
		cout << temp.get_nick(temp) << endl;
		cout << temp.get_grad_year(temp) << endl;
		cout << temp.get_captain(temp) << endl;
	}
	
}

void handle_close()
{
	list_da_users.reserve(list_da_users.size() + from_other.size());
	//list_da_users.insert(list_da_users.end(), list_da_users.begin(), list_da_users.end());
	list_da_users.insert(list_da_users.end(), from_other.begin(), from_other.end());

	
	cout << "handle close" << endl;
	int vec_siz = list_da_users.size();

	for(int i = 0; i < vec_siz; i++)
	{
		cout << "i = " << i << endl;
		User temp = list_da_users[i];
		
		cout << temp.get_UUID(temp) << endl;
		cout << temp.get_nick(temp) << endl;
		cout << temp.get_grad_year(temp) << endl;
		cout << temp.get_captain(temp) << endl;
	}

	to_file(list_da_users);

}


void sign_up_CB(Fl_Widget *w, void *p)
{
	//cout << "sign up callback" << endl;
	sign_up_screen.sign_them_up();

	from_other = sign_up_screen.get_users();

	cout << "sign up CB" << endl;
	int vec_siz = from_other.size();

	for(int i = 0; i < vec_siz; i++)
	{
		User temp = from_other[i];
		
		cout << temp.get_UUID(temp) << endl;
		cout << temp.get_nick(temp) << endl;
		cout << temp.get_grad_year(temp) << endl;
		cout << temp.get_captain(temp) << endl;
	}
	from_other = sign_up_screen.get_users();

}

void close_main_CB(Fl_Widget *w, void *p)
{
	from_other = sign_up_screen.get_users();
	int vec_siz = from_other.size();

	cout << "close main CB vector size: " << vec_siz << endl;

	cout << "close main CB" << endl;

	for(int i = 0; i < vec_siz; i++)
	{
		User temp = from_other[i];
		
		cout << temp.get_UUID(temp) << endl;
		cout << temp.get_nick(temp) << endl;
		cout << temp.get_grad_year(temp) << endl;
		cout << temp.get_captain(temp) << endl;
	}
	handle_close();
	//to_file(list_da_users);
	win->hide();
	
}


Controller::Controller()
{
	
}

int Controller::run_the_show()
{
    from_file();
    


    const int X = 400;
    const int Y = 400;

    win = new Fl_Window(X, Y, "SuperChat");



	rp_sign_up = new Fl_Button(270, 240, 60, 25, "Sign Up");
	rp_sign_up->callback((Fl_Callback *)sign_up_CB, 0);
	
	close_main = new Fl_Button(200, 240, 60, 25, "Close");
	close_main->callback((Fl_Callback *)close_main_CB,0);
    win->end();
    win->show();

    return Fl::run();


}
