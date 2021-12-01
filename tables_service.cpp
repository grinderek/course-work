//
// Created by danila on 2.12.21.
//

#include "tables_service.h"

void createTable(const string& sql) {
    try
    {
        sqlite3* DB;

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