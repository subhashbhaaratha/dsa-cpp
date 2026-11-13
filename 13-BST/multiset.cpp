#include<iostream>
#include<set>
using namespace  std ;
typedef multiset<int>::iterator it ;
int main()
{
    int arr[] ={10,10,20,10,30,20,30,30,30,80} ;
    int n = sizeof(arr)/sizeof(int) ;
    multiset<int> m(arr, arr + n) ;
    m.erase(20) ;
    for(auto i : m)
    {
        cout << i << " " ;
    }
    cout << endl ;
    cout << m.count(30) << endl ;
    auto it = m.find(30) ;
    cout << *it << endl ;
    pair<multiset<int>::iterator, multiset<int>::iterator> range = m.equal_range(30) ;
    for(auto it = range.first ; it != range.second ; it++)
    {
        cout << *it << " " ;
    }
    cout << endl ;
    for(auto it = m.lower_bound(10); it != m.upper_bound(80) ; it++)
    {
        cout << *it << " " ;
    }
    
}