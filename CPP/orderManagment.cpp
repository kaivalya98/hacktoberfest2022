#include<iostream>
using namespace std;
class Order{
   private:
        int itemNumber;
        char itemName[30];
        double itemPrice;
   public: 
        friend void getItemNumber(int);
        friend void getItemName(string);
        friend void getItemPrice(double);
};
void getItemNumber(int itemNumber){
    cout<<"The item Number of the Item is : "<<itemNumber<<endl;
}
void getItemName(string itemName){
    cout<<"The Name of the Item is : "<<itemName<<endl;
}
void getItemPrice(double itemPrice){
    cout<<"The Price of the Item is : "<<itemPrice;
}
int main()
{
  getItemNumber(1);
  getItemName("Smartphone");
  getItemPrice(15999.456);
return 0;
}