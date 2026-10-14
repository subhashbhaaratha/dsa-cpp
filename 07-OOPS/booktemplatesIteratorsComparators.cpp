#include<iostream>
#include<list>
#include<vector>
using namespace std;
template<class ForwardIterator, class T, class Compare>
ForwardIterator findEle(ForwardIterator start, ForwardIterator end, T key, Compare cmp)
{
    while(start!=end)
    {
        if(cmp(*start,key))
        return start ;
    start++ ;
    }
    return end ;
}
class Book{

    public:
    string name ;
    int price ;
        Book()
        {

        }
        Book(string name, int price)
        {
            this->name = name ;
            this->price = price ;
        }


};
class Compare
{
    public:
    bool operator()(Book A, Book B){
        if(A.name == B.name)
        return true ;
        else
        return false ;
    }

};

int main()
{
    Book b1("C++", 100) ;
    Book b2("Python", 120) ;
    Book b3("Java", 140) ;
    list<Book>l ;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);
    Book booktofind("C++", 110) ;
    Compare cmp ;
    auto it = findEle(l.begin(), l.end(), booktofind, cmp) ;
    if(it!= l.end())
    cout << "Book Present" ;
    else
    cout << "Book not present" ;


   
   


}