#include "cart.h"

Cart::Cart(int id, int custId) {
  Cart::id = id;
  Cart::custId = custId;
}

int Cart::getId() {
  return (Cart::id);
}

int Cart::getCustId() {
  return (Cart::custId);
}

void Cart::setId(int id) {
  Cart::id = id;
}

void Cart::setCustId(int id) {
  Cart::custId = id;
}