//
// Created by danila on 28.11.21.
//

#include "Service.h"

int getInt(int begin, int end) {
    int x = -1;
    do {
        cin >> x;
        if (!cin || x < begin || x > end || cin.get() != '\n') {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Please, try again" << std::endl;
            x = -1;
        }
    } while (x == -1);

    return x;
}

string getString() {
    string str;
    getline(cin, str);
    return str;
}

string quotesql( const string& s ) {
    return string("'") + s + string("'");
}

User authenticate(const string& login, const string& password) {
    sqlite3* DB;

    string sql = "SELECT * FROM USERS WHERE "
                 "LOGIN = " + quotesql(login) +
                 " AND PASSWORD = " + quotesql(password) + ";";

    try
    {
        int exit = 0;
        exit = sqlite3_open("test.db", &DB);
        cout << exit << " " << sql << endl;
        char* messageError;
        User user;
        sqlite3_stmt *stmt;
        exit = sqlite3_prepare_v2(DB, sql.c_str(), sql.length(), &stmt, nullptr);

        if (exit != SQLITE_OK) {
            cerr << "Error Authenticate" << endl;
        }
        else {
            while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
                user.setID(sqlite3_column_int(stmt, 0));
                user.setName(string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))));
                user.setRole(sqlite3_column_int(stmt, 4));
                user.setGroupID(sqlite3_column_int(stmt, 5));
            }
        }
        sqlite3_finalize(stmt);
        sqlite3_close(DB);

        return user;
    }
    catch (const exception & e)
    {
        cerr << e.what();
        return {};
    }
}

template <class T>
void show_vector(vector<T> objs) {
    int i = 1;
    for (auto obj : objs) {
        cout << "№" << i++ << " ";
        cout << obj.getName() << endl;
    }
}

template void show_vector<Question>(vector<Question> objs);
template void show_vector<Answer>(vector<Answer> objs);
template void show_vector<Test>(vector<Test> objs);
template void show_vector<Group>(vector<Group> objs);