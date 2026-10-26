#include<iostream>
#include<list>
using namespace std ;
class Queue{
    list<int>l ;
    public:
        void push(int d)
        {
            l.push_back(d) ;
        }
        bool empty()
        {
            return l.size() == 0 ;
        }
        void pop()
        {
            if(!empty())
            l.pop_front() ;
        }
        int front()
        {
            if(!empty())
            return l.front() ;
         return -1 ;
        }



};
int main()
{
    Queue q ;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop() ;
    }
}