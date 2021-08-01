#include "cart.h"
#include <iostream>

Cart::Cart() {
    Cart::id = 0;
    Cart::item = nullptr;
    Cart::size = 0;
}

int Cart::getId() {
    return (Cart::id);
}

void Cart::setId(int id) {
    Cart::id = id;
}

void Cart::addItem(Item* item) {
    // this should work like a linked-list / stack add function
   
    if (size == 0) {
        Cart::item = item;
    }
    else {
        (*item).setNext(Cart::item);
        Cart::item = item;
    }
    Cart::size++;
}

void Cart::getContent() {
    Item* currentItem = Cart::item;
    string listOfItems = "";
    int count = 0;

    while (count < Cart::size) {
        std::cout << currentItem->getName() << " --> ";
        currentItem = currentItem->getNext();
        count = count + 1;
    }
    std::cout << " end of list" << std::endl;
}