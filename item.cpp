#include "item.h"
#include <string>

using namespace std;

Item::Item(float price, string name) {
    Item::price = price;
    Item::name = name;
}

float Item::getPrice() {
    return (Item::price);
}

string Item::getName(){
    return (Item::name);
}