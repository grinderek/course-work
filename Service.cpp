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

void createTable() {
    sqlite3* DB;

    string sql = "CREATE TABLE IF NOT EXISTS USERS ("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "FULL_NAME TEXT NOT NULL, "
                 "LOGIN TEXT NOT NULL, "
                 "PASSWORD TEXT NOT NULL, "
                 "ROLE INTEGER NOT NULL );";

    try
    {
        int exit = 0;
        exit = sqlite3_open("test.db", &DB);
        cout << exit << " " << sql << endl;
        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            cerr << "Error Create Table" << endl;
            sqlite3_free(messageError);
        }
        else
            cout << "Table created successfully" << endl;
        sqlite3_close(DB);
    }
    catch (const exception & e)
    {
        cerr << e.what();
    }
}

string quotesql( const string& s ) {
    return string("'") + s + string("'");
}