#include "keypadController.h"

keypadController::keypadController(order * items)
{
  cart = items;
  cart->addObserver(this);
  display.refresh(*cart);
}

void keypadController::update()
{
  display.refresh(*cart);
}
