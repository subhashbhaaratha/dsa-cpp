#include<iostream>
#include<set>
using namespace std ;
int main()
{
    set<pair<int, int>>s ;
    s.insert({20,1}) ;
    s.insert({20,100}) ;
    s.insert({5,20}) ;
    s.insert({5,3}) ;
    s.insert({7,9}) ;
    s.erase(s.find({5,3})) ;
     s.insert({5,1}) ;
    auto it =  s.upper_bound({5,INT_MAX}) ;
    cout << it->first << " " << it->second << endl ;
    for(auto p : s)
    {
        cout << p.first << " " << p.second << endl ;
    }
}