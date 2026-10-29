#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
    long long  n ;
    cin >> n ;
    vector<long long > a(n) ;
    for(long long i = 0 ; i < n ; i++)
    {
        cin >> a[i] ;
    }
    vector<int>answer(n) ;
    stack<int> s ;
    
   for(int i = 0 ; i < n ; i ++)
   {
       while(!s.empty() && (a[i] > a[s.top()]))
       {
        answer[s.top()] = a[i] ;
        s.pop() ;
       }
       s.push(i) ;
   }
   for(int i = 0 ; i < n ; i++)
   {
       while(!s.empty() && (a[i] > a[s.top()]))
       {
       
        answer[s.top()] = a[i] ;
        
        s.pop() ;
       }
   }
   while(!s.empty())
   {
    answer[s.top()] = -1 ;
    s.pop() ;
   }
   for(int i = 0 ; i < n ; i++)
   {
    cout << answer[i] << " " ;
   }


}