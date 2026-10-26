#include<iostream>
#include<list>
#include<vector>
using namespace std ;

// class Stack
// {
//     int a[20] ;
//     int cs = 0 ;
//     int ms = 20 ;
//     public :
//       bool isFull()
//       {
//         return cs == ms  ;
//       }
//       void push(int d)
//       {
//         if(!isFull())
//         {
//             a[cs] = d ; 
//             cs++ ;
//         }
        
//       }
//        bool isEmpty()
//       {
//         return cs == 0 ;
//       }
//       void pop()
//       {
//         if(!isEmpty())
//         cs-- ;
//       }
//       int top()
//       {
//         if(!isEmpty())
//         return a[cs - 1] ;
//       }
     
// };
// class Stack
// {
//     list<int> l ;
//     public:
//       void push(int d)
//       {
//         l.push_front(d) ;
//       }
//        bool isEmpty()
//       {
//         return l.size() == 0 ;
//       }
//       void pop()
//       {
//         if(!isEmpty())
//         l.pop_front() ;
//       }
//       int top()
//       {
//         return l.front() ;
//       }
     
// };
class Stack 
{
    vector<int> v ;
    int cs = 0 ;
    public :
    bool isEmpty()
    {
        return v.size() == 0 ;
    }
    void push(int d)
    {
        
        v.push_back(d) ;
    }
    void pop()
    {
        if(!isEmpty())
        v.pop_back() ;
    }
    int top()
    {
        return v[v.size() - 1] ;
    }
   

};

int main()
{
    Stack s ;
    for(int i = 1 ; i < 6  ; i++)
    {
        s.push(i*i) ;
    }
    while(!s.isEmpty())
    {
        cout << s.top() << " " ;
        s.pop() ;
    }
   
}
