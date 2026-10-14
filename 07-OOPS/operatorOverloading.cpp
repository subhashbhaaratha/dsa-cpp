#include<iostream>
using namespace std;
class Complex{
    
    int real ;
    int img ;
    public:
    Complex()
    {
        real = 0 ;
        img = 0 ;
    }
    Complex(int r, int i)
    {
        real = r ;
        img = i ;
    }
   
    void setReal(const int r)
    {
        real = r ;
    }
    void setImg(const int i)
    {
        img = i ;
    }
    int  getReal() const
    {
        return real ;
    }
    int  getImg() const
    {
        return img ;
    }

    void print() const
    {
        if(img > 0)
        {
            cout << real << "+" << img << "i" << endl ;
        }
        else{
            cout << real << "-" << -img << "i" << endl ;
        }
    }
    void add(const Complex &x)
    {
        real += x.real ;
        img += x.img ;
    }
    Complex& operator+( Complex &x)
    {
        real += x.real ;
        img += x.img ;
        return *this ;
        
    }
    void operator!()
    {
        img = -img ;
    }
    int  operator[](string s)
    {
        // if(img > 0)
        // cout << real << "+" << img << "i" << s << endl ;
        // else
        // cout << real << "-" << -img << "i" << s << endl ;
        if(s == "real")
        return real ;
        else
        return img ;

    }
};
istream& operator>>(istream& is, Complex &c)
{
    int r1, i1 ;
    is >> r1 >> i1 ;
    c.setReal(r1) ;
    c.setImg(i1) ;
    return is ;
}
ostream& operator<<(ostream& os ,Complex &c)
{
    c.print() ;
    return os ;

}

int main()
{
 Complex c1(5, 3) ;
 Complex c2 ;
 c2.setReal(1) ;
 c2.setImg(-2) ;
 c1.print() ;
 c2.print() ;
// c1.add(c2) ;
 
c1 + c2 + c2;
!c1 ;

c1.print() ;
c2.print() ;
//  c1[" is cool "] ;
cout << c1["real"] << endl ;
cout << c1["img"] << endl ;

Complex d1, d2, d3;
cin >> d1 >> d2 >> d3 ; 
cout << d1 << d2 << d3 ; 
}