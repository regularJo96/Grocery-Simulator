#include "item.h"
#include <string>

using namespace std;


Item::Item(float price, string name) {
    Item::price = price;
    Item::name = name;
    Item::nextItem = nullptr;
}

float Item::getPrice() {
    return (Item::price);
}

string Item::getName() {
    return (Item::name);
}

Item* Item::getNext() {
    return Item::nextItem;
}

void Item::setNext(Item* item) {
    Item::nextItem = item;
}