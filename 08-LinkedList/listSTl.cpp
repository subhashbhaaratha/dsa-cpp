#include <iostream>
#include <list>
using namespace std ;
int main()
{
    list<int> l ;
    list<int>l1{1,2,3,4,5};
    list<string>l2{"mango", "apple", "guava", "banana"} ;
    for(auto s: l2)
    {
        cout << s << "-->" ;
    }
    cout << endl ;
    l2.push_back("pineapple") ; 
      for(auto s: l2)
    {
        cout << s << "-->" ;
    }
    cout << endl ;
    l2.pop_back() ;
      for(auto s: l2)
    {
        cout << s << "-->" ;
    }
    cout << endl ;
    l2.push_front("pineapple") ; 
      for(auto s: l2)
    {
        cout << s << "-->" ;
    }
    cout << endl ;
    l2.pop_front() ;
      for(auto s: l2)
    {
        cout << s << "-->" ;
    }
    cout << endl ;
    l2.sort() ;
      for(auto s: l2)
    {
        cout << s << "-->" ;
    }
    cout << endl ;
    l2.reverse() ;
      for(auto s: l2)
    {
        cout << s << "-->" ;
    }
    cout << endl ;
    l2.remove("guava") ;
      for(auto s: l2)
    {
        cout << s << "-->" ;
    }
    cout << endl ;
    cout << l2.front() ;
    cout << endl ;
    cout << l2.back() ;
    cout << endl;
    for(auto it = l2.begin() ; it != l2.end() ; it++)
    {
        cout << (*it) << " --> " ;
    }
    cout << endl ;
    l2.push_back("orange") ;
    l2.push_back("kiwi") ;
     l2.push_back("orange") ;
    
    // string f ;
    // cin >> f ;
    // l2.remove(f) ;
     for(auto s: l2)
    {
        cout << s << "-->" ;
    }
    cout << endl ;
    auto it = l2.begin() ;
    it++ ;
    l2.erase(it) ;
     for(auto s: l2)
    {
        cout << s << "-->" ;
    }
    cout << endl ;
    it = l2.begin() ;
    it++ ;
    it++ ;
    l2.insert(it, "banana") ;
     for(auto s: l2)
    {
        cout << s << "-->" ;
    }



}