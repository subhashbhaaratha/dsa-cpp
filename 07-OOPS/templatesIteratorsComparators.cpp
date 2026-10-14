#include<iostream>
#include<list>
#include<vector>
using namespace std;
template<class ForwardIterator, class T>
ForwardIterator findElement(ForwardIterator start, ForwardIterator end, T key )
{
    while(start!=end)
    {
        if(*start == key)
        return start ;
    start++ ;
    }
    return end ;
}

int main()
{
    list<int>l ;
    l.push_back(1);
    l.push_back(3);
    l.push_back(5);
    l.push_back(2);
   
    auto it = findElement(l.begin(), l.end(), 5) ;
    cout << *it ;


}