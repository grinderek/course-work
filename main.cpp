#include <iostream>
#include "User.h"
#include "Service.h"
#include "SqlGateway.h"
#include "TestInterface.h"
#include "GroupInterface.h"
#include "TestingInterface.h"
#include "Authorization.h"
#include <cstdlib>
#include "Guest.h"

int main() {
    setlocale(LC_ALL, "Russian");

    SqlGateway DB;

    DB.createUsersTable();
    DB.createTestsTable();
    DB.createQuestionsTable();
    DB.createAnswersTable();
    DB.createCorrectAnswersTable();
    DB.createGroupsTable();
    DB.createGroupTestsTable();
    DB.createUsersTestsTable();

    vector<unique_ptr<User>> user;
    user.emplace_back(new Guest);
    while (true) {
        user = user[0]->menu();
    }

    return 0;
}
