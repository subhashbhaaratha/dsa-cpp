#include<iostream>
#include<vector>
using namespace std ;
template<typename T,typename U>
class Stack 
{
    vector<T> v ;
    vector<U>v2 ;
    int cs = 0 ;
    public :
    bool isEmpty()
    {
        return v.size() == 0 ;
    }
    void push(T d)
    {
        
        v.push_back(d) ;
    }
    void pop()
    {
        if(!isEmpty())
        v.pop_back() ;
    }
    T top()
    {
        return v[v.size() - 1] ;
    }
   

};

int main()
{
    Stack<char, int> s ;
    for(int i = 65 ; i < 71  ; i++)
    {
        s.push(i) ;
    }
    while(!s.isEmpty())
    {
        cout << s.top() << " " ;
        s.pop() ;
    }
   
}
