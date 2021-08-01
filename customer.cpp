#include "customer.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

Customer::Customer() {
    Customer::setName("John Doe");
    Customer::setId(0);
}

Customer::Customer(string name, int id) {
    Customer::setName(name);
    Customer::setId(id);
    Customer::setShopTime();
    std::cout << name << " arrived. They plan to shop for " << shopTime << " minutes" << endl;
}

string Customer::getName() {
    return (Customer::name);
}

int Customer::getId() {
    return (Customer::id);
}

int Customer::getShopTime() {
    return (Customer::shopTime);
}
void Customer::setName(string name) {
    Customer::name = name;
}

void Customer::setId(int id) {
    Customer::id = id;
}

void Customer::setShopTime() {
    srand(time(NULL));
    Customer::shopTime = ((rand() % 30) + 5);
}

// void Customer::chooseCart(Cart* cart) {

// }

void Customer::placeItemInCart(Cart* cart, Item* item) {
    // cart.addItem(item);

}

