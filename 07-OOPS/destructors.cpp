#include<iostream>
using namespace std;
class Car{
    private:
        float price ;


    public:
        int model_no ;
        char* name ;
    Car()
    {
        name = NULL ;
    }

    Car(int p, int m, const char* n)
    {
        price = p ;
        model_no = m ;
        name = new char[strlen(n)+1] ;
        strcpy(name, n) ;
    }
    Car(const Car &X)
    {
        price = X.price ;
        model_no = X.model_no ;
       // name = X.name shallow Copy;
       //Deep Copy
       name = new char[strlen(X.name)+1] ;
       strcpy(name , X.name) ; 
    }

    void set_price(float p)
    {
        price = p ;
    }

    void print()
     {
            cout << "ModelNo: " << model_no << endl ;
            cout << "Price: " << price << endl ;
            cout<< "Name: " << name << endl ;
     }
     ~Car(){
        cout<<"Destructor is called for car :" << name ;
        if(name != nullptr){
            delete [] name ;
        }

     }

};
int main()
{

    Car c(100, 200, "BMW") ;
    Car d(c) ;
    
    d.set_price(400) ;
    d.name[0] = 'A' ;

    c.print() ;
    d.print() ;

    Car *e = new Car(10,20,"Ferrari") ;
    e->print() ;

    delete e ;

}