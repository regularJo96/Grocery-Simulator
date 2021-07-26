#include "item.h"

#pragma once

class Cart {
private:
  int id;
  int custId;
  Item* item;

public:
  Cart(int id, int custId);

  int getId();
  int getCustId();
  void setId(int id);
  void setCustId(int id);

  void placeItem(Item* item);
};