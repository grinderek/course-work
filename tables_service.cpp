//
// Created by danila on 2.12.21.
//

#include "tables_service.h"

int SQLOperation(const string& sql) {
    try
    {
        sqlite3* DB;

        int exit = 0;
        exit = sqlite3_open("test.db", &DB);
        //cout << exit << " " << sql << endl;
        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            cerr << sql << endl;
            sqlite3_free(messageError);
        }
        //else
            //cout << "Table created successfully" << endl;
        int id = sqlite3_last_insert_rowid(DB);
        sqlite3_close(DB);
        return id;
    }
    catch (const exception & e)
    {
        cerr << e.what();
    }


    return -1;
}

void createQuestionsTable() {
    SQLOperation("CREATE TABLE IF NOT EXISTS QUESTIONS ("
                "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                "TEXT_OF_QUESTION TEXT NOT NULL, "
                "TEST_ID INTEGER, "
                "  CONSTRAINT fk_tests\n"
                "    FOREIGN KEY (TEST_ID)\n"
                "    REFERENCES TESTS (ID)\n"
                "    ON DELETE CASCADE"
                "    ON UPDATE CASCADE);");
}

void createAnswersTable() {
    SQLOperation("CREATE TABLE IF NOT EXISTS ANSWERS ("
                "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                "TEXT_OF_ANSWER TEXT NOT NULL, "
                "QUESTION_ID INTEGER, "
                "  CONSTRAINT fk_questions\n"
                "    FOREIGN KEY (QUESTION_ID)\n"
                "    REFERENCES QUESTIONS (ID)\n"
                "    ON DELETE CASCADE"
                "    ON UPDATE CASCADE);");
}

void createCorrectAnswerTable() {
    SQLOperation("CREATE TABLE IF NOT EXISTS CORRECT_ANSWERS ("
                         "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "ANSWER_ID INTEGER, "
                         "QUESTION_ID INTEGER, "
                         "  CONSTRAINT fk_questions\n"
                         "    FOREIGN KEY (QUESTION_ID)\n"
                         "    REFERENCES QUESTIONS (ID)\n"
                         "    ON DELETE CASCADE\n"
                         "    ON UPDATE CASCADE\n"
                         "  CONSTRAINT fk_answers \n"
                         "    FOREIGN KEY (ANSWER_ID)\n"
                         "    REFERENCES ANSWERS (ID)\n"
                         "    ON DELETE CASCADE\n"
                         "    ON UPDATE CASCADE);");
}