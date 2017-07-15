#include "Log_In.h"

Log_In::Log_In()
{

}

void Log_In::set_default_user()
{
    from_file.open("File_User.txt");
    int counter = 0;

    string name, captain, UUID_s, year_s;
    int UUID, year;

    while(from_file >> UUID_s >> name >> year_s >> captain)
    {
        if(counter > 0)
        {
            UUID = stoi(UUID_s);
            year = stoi(year_s);

            User temp(name, UUID, year, captain);
            default_user = temp;
        }

        counter++;

    }

    from_file.close();
}

User Log_In::get_user()
{
    return default_user;
}
