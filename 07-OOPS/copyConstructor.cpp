#include<iostream>
using namespace std;
class Car{

    private:
        float price ;

    public:
        int model_no ;
        string name ;
        Car()
        {
           cout << "Constructor is called" << endl;
        }
        Car(float p,int model,string na)
        {
            price = p ;
            model_no = model ;
            name = na ;
        }
        Car (Car &x)
        {
            cout << "Copy Constructor" ;
            price = x.price ;
            model_no = x.model_no ;
            name = x.name ;
        }

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
            price = price * (1-x);
            return price;
        }


};
int main()
{
    Car c;
    Car d(78, 100, "Audi") ;
    cout << "Car D:" << endl ;
    d.print() ;
    Car e(d) ;
    cout << "Car E:" << endl ;
    e.print() ;
    e.set_price(200) ;
    cout << "Car E Updated:" << endl ;
    e.print() ;
    Car f = e ;
    cout << "Car F:" << endl ;
    f.print() ;
    c.model_no = 23 ;
    c.name = "BMW" ;
    c.set_price(100);
    c.print() ;
    
}