#include<iostream>
#include<set>
using namespace std ;
class person_compare{
    public:
     bool operator()(pair<string, int> p1 , pair<string, int> p2)
     {
        return p1.second < p2.second ;
     }
};
int main()
{
    multiset<pair<string,int> , person_compare> m ;
    m.insert({"B",35}) ;
    m.insert({"A",150}) ;
    m.insert({"C",200}) ;
    m.insert({"D",120}) ;
    for(auto p : m)
    {
        cout << p.first << " " << p.second << endl ;
    }

    
}