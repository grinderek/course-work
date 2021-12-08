//
// Created by danila on 3.12.21.
//

#include "SqlGateway.h"

int SqlGateway::SQLOperation(const string &sql) {
    try
    {
        int exit = 0;
        exit = sqlite3_open(this->name, &DB);
        //cout << exit << " " << sql << endl;
        char* messageError;
        exit = sqlite3_exec(this->DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            cerr << messageError << endl;
            sqlite3_free(messageError);
        }
        //else
        //cout << "Table created successfully" << endl;
        int id = sqlite3_last_insert_rowid(this->DB);
        sqlite3_close(this->DB);
        return id;
    }
    catch (const exception & e)
    {
        cerr << e.what();
    }


    return -1;
}

void SqlGateway::createUsersTable() {
    SQLOperation("CREATE TABLE IF NOT EXISTS USERS ("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "FULL_NAME TEXT NOT NULL, "
                 "LOGIN TEXT NOT NULL UNIQUE, "
                 "PASSWORD TEXT NOT NULL, "
                 "ROLE INTEGER NOT NULL,"
                 "GROUP_ID INTEGER NOT NULL,"
                 "  CONSTRAINT fk_groups\n"
                 "    FOREIGN KEY (GROUP_ID)\n"
                 "    REFERENCES GROUPS (ID)\n"
                 "    ON DELETE CASCADE"
                 "    ON UPDATE CASCADE);");
}

void SqlGateway::createQuestionsTable() {
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

void SqlGateway::createAnswersTable() {
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

void SqlGateway::createCorrectAnswerTable() {
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

void SqlGateway::createGroupTable() {
    SQLOperation("CREATE TABLE IF NOT EXISTS GROUPS ("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "NUMBER_OF_GROUP TEXT NOT NULL UNIQUE);");
}

void SqlGateway::createTestsTable() {
    SQLOperation("CREATE TABLE IF NOT EXISTS TESTS ("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "NAME_OF_TEST TEXT NOT NULL, "
                 "NUMBER_OF_QUESTIONS INTEGER NOT NULL, "
                 "USER_ID INTEGER, "
                 "  CONSTRAINT fk_users\n"
                 "    FOREIGN KEY (USER_ID)\n"
                 "    REFERENCES USERS (ID)\n"
                 "    ON DELETE CASCADE);");
}

void SqlGateway::createGroupTestsTable() {
    SQLOperation("CREATE TABLE IF NOT EXISTS GROUP_TESTS ("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "GROUP_ID INTEGER, "
                 "TEST_ID INTEGER, "
                 "  CONSTRAINT fk_groups\n"
                 "    FOREIGN KEY (GROUP_ID)\n"
                 "    REFERENCES GROUPS (ID)\n"
                 "    ON DELETE CASCADE\n"
                 "    ON UPDATE CASCADE\n"
                 "  CONSTRAINT fk_tests \n"
                 "    FOREIGN KEY (TEST_ID)\n"
                 "    REFERENCES TESTS (ID)\n"
                 "    ON DELETE CASCADE\n"
                 "    ON UPDATE CASCADE);");
}

void SqlGateway::createUsersTestsTable() {
    SQLOperation("CREATE TABLE IF NOT EXISTS USERS_TESTS ("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "MARK INTEGER NOT NULL, "
                 "USER_ID INTEGER, "
                 "TEST_ID INTEGER, "
                 "  CONSTRAINT fk_users\n"
                 "    FOREIGN KEY (USER_ID)\n"
                 "    REFERENCES USERS (ID)\n"
                 "    ON DELETE CASCADE\n"
                 "    ON UPDATE CASCADE\n"
                 "  CONSTRAINT fk_tests \n"
                 "    FOREIGN KEY (TEST_ID)\n"
                 "    REFERENCES TESTS (ID)\n"
                 "    ON DELETE CASCADE\n"
                 "    ON UPDATE CASCADE);");
}

SqlGateway::SqlGateway() {
    this->name = "test.db";
}

template<class T>
vector <T> SqlGateway::getData(string sql) {
    try
    {
        int exit = 0;
        exit = sqlite3_open(this->name, &DB);
        cout << exit << " " << sql << endl;
        char* messageError;
        vector<T> objs;
        sqlite3_stmt *stmt;
        exit = sqlite3_prepare_v2(DB, sql.c_str(), sql.length(), &stmt, nullptr);

        if (exit != SQLITE_OK) {
            cerr << "Error Authenticate" << endl;
        }
        else {
            while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
                T obj;

                obj.get_data(stmt);
                objs.push_back(obj);
            }
        }
        sqlite3_finalize(stmt);
        sqlite3_close(DB);

        return objs;
    }
    catch (const exception & e)
    {
        cerr << e.what();
        return {};
    }
}

template vector<Answer> SqlGateway::getData<Answer>(string sql);
template vector<Question_Many_Variants> SqlGateway::getData<Question_Many_Variants>(string sql);
template vector<Test> SqlGateway::getData<Test>(string sql);
template vector<JustInt> SqlGateway::getData<JustInt>(string sql);
template vector<Group> SqlGateway::getData<Group>(string sql);
template vector<User> SqlGateway::getData<User>(string sql);