//
// Created by danila on 8.12.21.
//

#include "App.h"

template<class T>
void App::add() {
    T obj;
    cin >> obj;
    obj.add_to_base();
}