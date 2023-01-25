#include "read_base.h"

base::base(string base_name)
{
    ifstream file(base_name);
    string user;
    while(getline(file, user)) {
        DataBase[user.substr(0,user.find(sep))] = user.substr(user.find(sep)+1);
    }
    file.close();
}

bool base::check_user(string user)
{
    bool result = false;

    auto it = DataBase.begin();
    cout << "База клиентов:" << endl;
    for (int i = 0; it != DataBase.end(); it++, i++) {

        cout << it->first << " : " << it->second << '\n';
        if(it->first == user) {

            result = true;
            break;
        }
    }
    if (DataBase.count(user) != 1) {
        throw name_error(string("error Wrong ID"), false);
        return result;
    }
}
