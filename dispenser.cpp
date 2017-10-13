#include <iostream>
#include "dispenser.h"

using namespace std;

int dispenser::getBalance() const
{
  return cash;
}

void dispenser::acceptAmount(int in)
{
  cash = cash + in;
}

dispenser::dispenser(int cashIn)
{
  if(cashIn >= 0)
  {
    cash = cashIn;
  }
  else
  {
    cash = 1700;
  }

}
