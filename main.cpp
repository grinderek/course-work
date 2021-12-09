#include <iostream>
#include "User.h"
#include "Service.h"
#include "SqlGateway.h"
#include "tests_service.h"
#include "groups_service.h"
#include "testing_service.h"
#include "CRUD.h"
#include <cstdlib>
#include "Guest.h"

int main() {
    setlocale(LC_ALL, "Russian");

    SqlGateway DB;

    DB.createUsersTable();
    DB.createTestsTable();
    DB.createQuestionsTable();
    DB.createAnswersTable();
    DB.createCorrectAnswerTable();
    DB.createGroupTable();
    DB.createGroupTestsTable();
    DB.createUsersTestsTable();

    vector<unique_ptr<User>> user;
    user.emplace_back(new Guest);
    while (true) {
        user = user[0]->menu();
    }

    return 0;
}
