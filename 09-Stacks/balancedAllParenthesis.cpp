#include<iostream>
#include<stack>
using namespace std ;
bool isValid(string s)
{
    int n = s.length() ;
    stack<char> stk ;
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(' )
        {
            stk.push(s[i]) ;
        }
        else if(s[i] == '}')
        {
            if(stk.empty())
            {
                return false ;
            }
            else if(stk.top() == '{')
            {
                stk.pop() ;
            }
            else
            {
                return false ;
            }
        }
        else if(s[i] == ']')
        {
            if(stk.empty())
            {
                return false ;
            }
            else if(stk.top() == '[')
            {
                stk.pop() ;
            }
            else
            {
                return false ;
            }
        }
        else if(s[i] == ')')
        {
            if(stk.empty())
            {
                return false ;
            }
            else if(stk.top() == '(')
            {
                stk.pop() ;
            }
            else
            {
                return false ;
            }
        }
    }
    return stk.empty() ;
}
int main()
{
    string s ;
    cin >> s ;
    if(isValid(s))
    {
        cout << "true" ;
    }
    else
    {
        cout << "false" ;
    }
}