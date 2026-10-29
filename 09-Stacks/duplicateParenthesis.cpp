#include<iostream>
#include<stack>
using namespace std ;
bool isValid(string s)
{
    int n ;
    n = s.length() ;
    stack<char>stk ;
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] != ')')
        {
            stk.push(s[i]) ;
        }
        else
        {
            if(stk.top() == '(')
            {
                return false ;
            }
            while(stk.top() != '(')
            {
                stk.pop() ;
            }
            stk.pop() ;     
        }
    }
    return true ;
}
int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        string s ;
        cin >> s ;
          if(isValid(s))
          {
            cout << "Not Duplicates"  << endl ;
          }
          else
          {
            cout << "Duplicate" << endl ;
          }
    }
}