#include <iostream>
#include "User.h"
#include "Service.h"
#include "sqlite3.h"
#include "CRUD.h"
#include <cstdlib>

int main() {
    setlocale(LC_ALL, "Russian");

    createUsersTable("USERS");

    User user;

    while (true) {
        if (user.getName() == "...") {
            cout << "Здравствуйте! Введите номер вашего действия" << endl;
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
                    cout << "There is not such option" << endl;
            }
        }
        else {
            cout << "Happy testing!" << endl;
            return 0;
        }
    }

    return 0;
}
