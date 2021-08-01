#include "cart.h"

Cart::Cart(int id) {
    Cart::id = id;
}

int Cart::getId() {
    return (Cart::id);
}

void Cart::setId(int id) {
    Cart::id = id;
}

void Cart::addItem(Item* item){
    // this should work like a linked-list / stack add function
    Item* head = Cart::item;
    
    if(head==NULL){
        Cart::item = item;
    }
    else{
        //the order does not matter, so might as well just tack it on to the end.
        // (*Cart::item).nextItem = item;
    }
}