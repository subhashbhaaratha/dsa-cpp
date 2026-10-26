#include<iostream>
#include<queue>
using namespace std ;
class Stack{
    queue<int> q1 ;
    queue<int> q2 ;
    public: 
        bool empty()
        {
            return q1.empty() && q2.empty() ;
        }
        void push(int d)
        {
            if(q1.empty() && q2.empty())
            {
                q1.push(d) ;
            }
            else if(!q1.empty())
            {
                q1.push(d) ;
            }
            else 
            {
                q2.push(d) ;
            }
            
        }
        void pop()
        {
            if(!q1.empty())
            {
                int k = q1.size() - 1 ;
                while(k--)
               {
                q2.push(q1.front());
                q1.pop() ;
                }
                
               q1.pop() ;
            }
            else
            {

                int k = q2.size() - 1 ;
                while(k--)
               {
                q1.push(q2.front());
                q2.pop() ;
                }
               q2.pop() ;
            }
            
        }
        int top()
        {
            if(!q1.empty())
            {
                int k = q1.size() - 1 ;
                while(k--)
               {
                q2.push(q1.front());
                q1.pop() ;
                }
                q2.push(q1.front());
                int d = q1.front();
                q1.pop() ;
               return d ;
            }
            else
            {

                int k = q2.size() - 1 ;
                while(k--)
               {
                q1.push(q2.front());
                q2.pop() ;
                }
                 q1.push(q2.front());
                int d = q2.front() ;
                q2.pop() ;
               return d ;
            }
        }
      




};
class Stack2{
    queue<int> q1 ;
    queue<int> q2 ;
    public:
        bool empty()
        {
            return q1.empty() && q2.empty() ;
        }
        void push(int d)
        {
            if(q1.empty() && q2.empty())
            {
                q1.push(d) ;
                return ;
            }
            if(q2.empty())
            {
                q2.push(d) ;
                while(!q1.empty())
                {
                    q2.push(q1.front());
                    q1.pop() ;
                }
            }
            else
            {
                q1.push(d) ;
                while(!q2.empty())
                {
                    q1.push(q2.front());
                    q2.pop() ;
                }
            }

        }
        void pop()
        {
            if(q1.empty() && q2.empty())
            return ;
            if(!q1.empty())
            q1.pop() ;
            else
            q2.pop() ;

        }
        int top()
        {
             if(q1.empty() && q2.empty())
            return -1;
            if(!q1.empty())
            return q1.front() ;
            else
            return q2.front() ;
        }




};
int main()
{
    Stack2 s ;
    for(int i = 0 ; i < 6 ; i++)
    {
        s.push(i) ;
    }
    while(!s.empty())
    {
        cout << s.top() << " " ;
        s.pop() ;
    }
}