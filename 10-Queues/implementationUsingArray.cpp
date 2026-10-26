#include<iostream>
using namespace std ;

class Queue{

    int* arr ;
    int f,r,cs,ms ;

    public:
      Queue()
      {
        cs = 0 ;
        ms = 5 ;
        f = 0 ;
        r = ms - 1 ;
        arr = new int[ms] ; 
      }
      ~Queue()
      {
        delete [] arr ;
      }
      bool empty()
      {
        return cs == 0 ;
      }
      bool full()
      {
        return cs == ms ;
      }
      void push(int d)
      {
         if(!full())
         {
            arr[(r + 1)% ms] = d ;
            r = (r + 1) % ms ;
            cs++ ;
         }
      }
      void pop()
      {
        if(!empty())
        {
            f = ( f + 1 ) % ms ;
            cs-- ;
        }
      }
      int front()
      {
        if(!empty())
        {
            return arr[f] ;
        }
        return -1;
      }

};



int main()
{
    Queue q ;
    for(int i = 0 ; i < 5 ; i++)
    {
        q.push(i*i*i) ;
    }
    q.push(125) ;
     while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop() ;
    }
    cout << endl ;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(125) ;
    q.pop() ;
    q.push(216) ;
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop() ;
    }

}