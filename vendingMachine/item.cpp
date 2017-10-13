#include <iostream>
#include "item.h"

using namespace std;

int item::getNoOfItems() const
{
  return numItems;
}
int item::getCost() const
{
  return cost;
}

void item::makeSale()
{
  numItems--;
}

item::item(int setItems, int setCost)
{
  if(setItems >= 0)
  {
    numItems = setItems;
  }
  else
  {
    numItems = 50;
  }
  if (setCost >= 0)
  {
    cost = setCost;
  }
  else
  {
      cost = 50;
  }
}
