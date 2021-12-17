//
// Created by danila on 17.12.21.
//

#ifndef COURSE_TEST_INTERFACE_H
#define COURSE_TEST_INTERFACE_H
#include "SqlGateway.h"

using namespace std;

template<class T>
class Interface {
public:
    static void change(string sql) {
        SqlGateway DB;

        vector<T> objs = DB.getData<T>(sql);

        if (objs.empty()) {
            cout << "Нет доступных объектов для изменения" << endl;
            return;
        }

        while (true) {
            cout << "Выберите номер объекта, который хотите изменить(0 для выхода)" << endl;
            show_vector<T>(objs);

            int id = getInt(0, objs.size());
            if (id == 0) {
                break;
            }

            objs[--id].change();
        }
    }

};

#endif //COURSE_TEST_INTERFACE_H
