#include<iostream>
using namespace std;
class Car{
    private:
        float price ;


    public:
        int model_no ;
        char* name ;
        const int msp;
    Car():msp(99)
    {
        name = NULL ;
    }

    Car(int p, int m, const char* n, int minprice=99): price(p), msp(minprice)
    {
     
        model_no = m ;
        name = new char[strlen(n)+1] ;
        strcpy(name, n) ;
    }
    Car(const Car &X):msp(X.msp)
    {
        price = X.price ;
        model_no = X.model_no ;
       // name = X.name shallow Copy;
       //Deep Copy
       name = new char[strlen(X.name)+1] ;
       strcpy(name , X.name) ; 
    }

    Car& operator=(const Car &X)
    {
        delete [] name ;
        if(this==&X)
        return *this ;
         price = X.price ;
        model_no = X.model_no ;
       // name = X.name ;//shallow Copy;
       name = new char[strlen(X.name)+1] ;
       strcpy(name , X.name) ; 
       return *this;

    }

    void set_price(float p)
    {
        price = p ;
    }
     float get_price()const
        {
            return price ;
        }
    
        float discounted_price(const float x)
        {
            price = price * (1-x);
            return price;
        }

    void print() const
     {
            cout << "ModelNo: " << model_no << endl ;
            cout << "Price: " << price << endl ;
            cout<< "Name: " << name << endl ;
     }

};
int main()
{

    Car c(100, 200, "BMW") ;
    cout << c.msp << endl ;
    //c.msp++
    Car d ;
    d=c;
    
    d.set_price(400) ;
    d.name[0] = 'A' ;

    c.print() ;
    d.print() ;



}