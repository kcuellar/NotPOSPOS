#ifndef _KEYPADCONTROLLER_H_
#define _KEYPADCONTROLLER_H_
#include "order.h"
#include "customerView.h"

// (1) inherit IObserver, (2) implement the void update() function

class keypadController : public IObserver
{
private:
  order *cart;
  customerView display;
public:
  keypadController(order *);
  void update();
};

#endif
