#include <iostream> //includes functionality to read and write from streams
#include "item.h" //when I include other header files, I need to use ""
#include "dispenser.h"

using namespace std; //Instead of using std::cout, I can write just cout

void menu(); //functions
void sell(item&, dispenser&);
//Privde the each quantity
int MtnDewQty = 5;
int DrPepperQty = 10;
int CokeQty = 4;
int RedBullQty = 3;
int WaterQty = 8;

int main()
{
  dispenser counter;

  int choice;
  item MtnDew(100,10); //amount and price
  item DrPepper(100 ,1);
  item Coke(20,15);
  item RedBull(30,30);
  item Water(40,50);

  menu(); //display the menu
  cin >> choice; //get the inputs from users
  while (choice != 9)
  {
    switch(choice)
    {
      case 1:
        sell(MtnDew, counter);
        MtnDewQty--;
        break;
      case 2:
        sell(DrPepper,counter);
         DrPepperQty--;
        break;
      case 3:
        sell(Coke, counter);
        CokeQty--;
        break;
      case 4:
        sell(RedBull, counter);
        RedBullQty--;
        break;
      case 5:
        sell(Water, counter);
        WaterQty--;
        break;
      default:
        cout << "Invalid Selection!!!!!" << endl;
    }
    menu(); //display the menu again
    cin >> choice;
  }
  return 0;

}

//Menu function
void menu()
{
  cout << "=========== WELCOME TO BIN'S FAVORITE DRINK MACHINE ===========" << endl;
  cout << "ENTER 1: Mtn Dew ~~ QTY = " << + MtnDewQty << endl;
  cout << "ENTER 2: Dr Pepper ~~ QTY = " << + WaterQty << endl;
  cout << "ENTER 3: Coke ~~ QTY = " << + CokeQty << endl;
  cout << "ENTER 4: Red Bull ~~ QTY = " << + RedBullQty << endl;
  cout << "ENTER 5: Water ~~ QTY = " << + WaterQty << endl;
  cout << "ENTER 9: TO EXIT" << endl;
  cout << "==============================================================" << endl;
}

void sell(item& product, dispenser& count)
{
  int amount1, amount2;

  if (product.getNoOfItems() > 0)
  {
    // cout << "How many do you want?" << endl;
    // cin >> itemAmount;
    cout << "Please deposit " << product.getCost() << " dollars." << endl;
    cin >> amount1;
    if(amount1 < product.getCost())
    {
      cout << "Please deposit another " << product.getCost() - amount1 << " dollars." << endl;
      cin >> amount2;
      amount1 = amount1 + amount2;
    }
    if(amount1 >= product.getCost())
    {
      count.acceptAmount(amount1);
      product.makeSale();
      cout << "GET YOUR ITEMS!!!" << endl;
      if(amount1 > product.getCost())
      {
        cout << "Change = " << amount1 - product.getCost() << " dollars." << endl;
      }
    }
    else
    {
      cout << "The amount is not enough, please take your money." << endl;
    }
    cout << "======================================================" << endl << endl;
  }
  else
  {
    cout << "ITEM IS CURRENTLY SOLD OUT." << endl;
  }
}
