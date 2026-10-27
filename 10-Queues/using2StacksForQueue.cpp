#include<iostream>
#include<stack>
using namespace std;
class queue{
    stack<int> s1 ;
    stack<int> s2 ;
    public:
    bool empty()
    {
        return s1.size() == 0 && s2.size() == 0 ;
    }
     void push(int d)
     {
        s1.push(d) ;
     }
     void pop()
     {
        if(empty())
        return ;
        while(!s1.empty())
        {
            int d = s1.top();
            s1.pop() ;
            s2.push(d) ;
        }
        s2.pop() ;
        while(!s2.empty())
        {
            int d = s2.top() ;
            s2.pop() ;
            s1.push(d) ;
        }
     }
     int front()
     {
         while(!s1.empty())
        {
            int d = s1.top();
            s1.pop() ;
            s2.push(d) ;
        }
        int ans = s2.top() ;
        while(!s2.empty())
        {
            int d = s2.top() ;
            s2.pop() ;
            s1.push(d) ;
        }
        return ans ;
     }
};
class queue2{
    stack<int> s1 ;
    stack<int>s2 ;
    public:
        bool empty()
        {
            return s1.size() == 0 && s2.size() == 0 ;
        }
        void push(int d)
        {
            if(s1.empty() && s2.empty())
            {
                s1.push(d) ;
            }
            else if(!s1.empty())
            {
                while(!s1.empty())
                {
                    int d1 = s1.top() ;
                    s1.pop() ;
                    s2.push(d1) ;
                }
                s2.push(d) ;
                while(!s2.empty())
                {
                    int d2 = s2.top() ;
                    s2.pop() ;
                    s1.push(d2) ;
                }
            }
        }
        void pop()
        {
            if(empty())
            return ;
            s1.pop() ;
        }
        int front()
        {
            return s1.top() ;
        }
};
int main()
{
    queue2 q ;
    for(int i = 0 ; i < 6 ; i++)
    {
        q.push(i*i*i*i) ;
    }
    while(!q.empty())
    {
        cout << q.front() << " " ;
        q.pop() ;
    }
}