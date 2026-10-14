#include<iostream>
using namespace std;
class Car{

    private:
        float price ;

    public:
        int model_no ;
        string name ;

        void print()
        {
            cout << "ModelNo: " << model_no << endl ;
            cout << "Price: " << price << endl ;
            cout<< "Name: " << name << endl ;
        }
        void set_price(float p)
        {
            float msp=111;
            if(p>0)
            {
                price = p ;
            }
            else
            {
                price = msp ;

            }
        }
        float get_price()
        {
            return price ;
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
    c.name = "BMW" ;
    cout << "Enter Price: " ;
    float p;
    cin>>p ;
    c.set_price(p) ;
    c.print();
   
    

   

}