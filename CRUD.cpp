//
// Created by danila on 28.11.21.
//
#include "CRUD.h"
#include <termios.h>
#include <unistd.h>

/*int getch() {
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}

string getpass(bool show_asterisk=true)
{
    const char BACKSPACE=127;
    const char RETURN=10;

    string password;
    unsigned char ch=0;

    while((ch=getch())!=RETURN)
    {
        if(ch==BACKSPACE)
        {
            if(password.length()!=0)
            {
                if(show_asterisk)
                    cout <<"\b \b";
                password.resize(password.length()-1);
            }
        }
        else
        {
            password+=ch;
            if(show_asterisk)
                cout <<'*';
        }
    }
    cout <<endl;
    return password;
}*/

int add_user(int role, int group_id) {
    SqlGateway DB;
    string full_name;
    cout << "Введите ФИО" << endl;
    full_name = getString();

    string login;
    cout << "Введите логин" << endl;
    login = getString();

    string password;
    cout << "Введите пароль" << endl;
    password = getString();

    string sql = "INSERT INTO USERS (FULL_NAME, LOGIN, PASSWORD, ROLE, GROUP_ID) VALUES ("
                 + quotesql(full_name) + ","
                 + quotesql(login) + ","
                 + quotesql(password) + ","
                 + to_string(role) + ","
                 + to_string(group_id) + ");";

    int id = DB.SQLOperation(sql);
    return id;
}


vector<unique_ptr<User>> login() {
    SqlGateway DB;

    string login;
    cout << "Введите логин" << endl;
    login = getString();

    string password;
    cout << "Введите пароль" << endl;
    password = getString();

    string sql = "SELECT * FROM USERS WHERE "
                 "LOGIN = " + quotesql(login) +
                 " AND PASSWORD = " + quotesql(password) + ";";

    vector<unique_ptr<User>> user;
    auto ans = DB.getData<User>(sql);
    if (!ans.empty()) {
        cout << "Здравствуйте, " << ans[0].getName() << endl;
        if (ans[0].getRole() == 1) {
            user.emplace_back(new Student(ans[0].getID(), ans[0].getName(), ans[0].getRole(), ans[0].getGroupID()));
        } else {
            user.emplace_back(new Teacher(ans[0].getID(), ans[0].getName(), ans[0].getRole(), ans[0].getGroupID()));
        }
    } else {
        cout << "Такого пользователя не существует" << endl;
        user.emplace_back(new Guest);
    }

    return user;
}