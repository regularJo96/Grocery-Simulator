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