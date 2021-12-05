#include <iostream>
#include "User.h"
#include "Service.h"
#include "sqlite3.h"
#include "tests_service.h"
#include "tables_service.h"
#include "groups_service.h"
#include "CRUD.h"
#include <cstdlib>

int main() {
    setlocale(LC_ALL, "Russian");

    createUsersTable();
    createTestsTable();
    createQuestionsTable();
    createAnswersTable();
    createCorrectAnswerTable();
    createGroupTable();
    createGroups_UsersTable();

    User user;

    while (true) {
        if (user.getName() == "...") {
            cout << "Введите номер вашего действия" << endl;
            cout << "1 - Войти в систему" << endl;
            cout << "2 - Зарегистрироваться" << endl;
            cout << "0 - Выйти" << endl;
            int op_men = getInt(0, 2);
            switch (op_men) {
                case 0:
                    cout << "До свидания!" << endl;
                    return 0;
                case 1:
                    user = login();
                    break;
                case 2:
                    add_user();
                    break;
                default:
                    cout << "Что-то пошло не так" << endl;
            }
        }
        else {
            if (user.getRole() == 1) {

            }
            else {
                cout << "Здравствуйте, " << user.getName() << endl;
                cout << "1 - Тесты" << endl;
                cout << "2 - Группы" << endl;
                cout << "0 - Выход" << endl;
                int op_men = getInt(0, 2);

                switch (op_men) {
                    case 0:
                        return 0;
                        break;
                    case 1:
                        tests_menu(user);
                        break;
                    case 2:
                        groups_menu(user);
                        break;
                    default:
                        cout << "Что-то пошло не так" << endl;
                }
            }
        }
    }

    return 0;
}
