#include<iostream>
#include<queue>
using namespace std ;
int main()
{
    int n ;
    cin >> n ;
    queue<int> q1 ;
    queue<int> q2 ;
    for(int i = 0 ; i < n ; i++)
    {
        int n0 ;
        cin >> n0 ;
        q1.push(n0) ;
    }
    for(int i = 0 ; i < n ; i++)
    {
        int n0 ;
        cin >> n0 ;
        q2.push(n0) ;
    }
    int count = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        while(q1.front() != q2.front())
        {
            int d = q1.front() ;
            q1.pop() ;
            q1.push(d) ;
            count++ ;
        }
        q1.pop() ;
        q2.pop() ;
        count++ ;
    }
    cout << count ;


}