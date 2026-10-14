#include<iostream>
using namespace std;
class Car{

        public:
        int model_no ;
        float price ;
        string name ;
        void print()
        {
            cout << "ModelNo: " << model_no << endl ;
            cout << "Price: " << price << endl ;
            cout<< "Name: " << name << endl ;
        }
        float discounted_price(float x)
        {
            price = price*(1-x);
            return price;
        }


};
int main()
{
    Car c;
    c.model_no = 23 ;
    c.price = 100 ;
    c.name = "BMW" ;
   
    c.print();
    cout << "give the discount percentage" << endl ;
    float discount;
    cin >> discount ;
    c.discounted_price(discount) ;
    c.print();

}