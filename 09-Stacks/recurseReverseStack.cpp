#include<iostream>
#include<stack>
using namespace std ;
void insert(stack<int>&s, int x)
{
    int n = s.size() ;
    if(n == 0)
    {
        s.push(x) ;
        return ;
    }
    int data = s.top() ;
    s.pop() ;
    insert(s, x) ;
    s.push(data) ;
}
void reverse(stack<int>&s)
{
    int n = s.size() ;
    if(n == 0)
    {
        return ;
    }
    int x = s.top() ;
    s.pop() ;
    reverse(s) ;
    insert(s, x);
}
int main()
{
    stack<int> s ;
    s.push(1) ;
    s.push(2) ;
    s.push(3) ;
    s.push(4) ;
    reverse(s) ;
    while(!s.empty())
    {
        cout << s.top() << endl ;
        s.pop() ;
    }

}