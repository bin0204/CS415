class dispenser
{
public:
  int getBalance() const;
  void acceptAmount(int);
  dispenser(int cashIn = 1700); //constructor
private:
  int cash;
};
