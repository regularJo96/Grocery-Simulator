#include "item.h"
#include <string>
#pragma once

using namespace std;

Item::Item(int id, string name) {
    Item::id = id;
    Item::name = name;
}

int Item::getId() {
    return (Item::id);
}

string Item::getName(){
    return (Item::name);
}

