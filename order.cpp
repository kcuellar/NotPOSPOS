#include "order.h"

order::order() {
  tax = 0.0725;
  closed = false;
}

order::order(double tax) {
  this->tax = tax;
  closed = false;
}

void order::addItem(item i) {
  if( !closed )
  {
    itemList.push_back(i);
  }
  // Call the function notifyObservers() within the model when 
  // the model's state changes, to make sure it updates anything observing it
  notifyObservers();
}

std::vector<item> order::getItems() {
  return itemList;
}

double order::getSubtotal() {
  double subtotal = 0;
  for(int i = 0; i < itemList.size(); i++) {
    subtotal += itemList[i].getPrice();
  }
  return subtotal;
}

double order::getTax() {
  return tax;
}

double order::getTotal() {
  return getSubtotal() * (1 + tax);
  notifyObservers();
}

double order::balance(double paid) {
  closed = true;
  return getTotal() - paid;
}
