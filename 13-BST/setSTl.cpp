#include<iostream>
#include<set>
using namespace std ;
int main()
{
    set<int>s ;
    for(int i = 0 ;i < 6 ; i++)
    {
        s.insert(i*i) ;
    }
    s.erase(9) ;
    auto it = s.find(25);
    s.erase(it) ;
    for(set<int>::iterator it = s.begin() ; it != s.end() ; it++)
    {
        cout << *it << " " ;
    }
}