class item
{
public:
  int getNoOfItems() const;
  int getCost() const;
  void makeSale();
  item(int setItems = 50, int setCost = 50);
private:
  int numItems;
  int cost;
};
