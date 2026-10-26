#include<iostream>
#include<stack>
using namespace std ;
bool isValidExp(char *s)
{
    int len = strlen(s) ;
    stack<char> s1 ;
    for(int i = 0 ; i < len; i++)
    {
        if(s[i] == '(')
        {
            s1.push('(') ;
        }
        else if(s[i] == ')')
        {
            if(s1.empty())
            {
                return false ;
            }
            else
            {
                s1.pop() ;
            }
        }
    }
    if(s1.empty())
    return true ;
    else
    return false ;
}
int main()
{
    char s[] = "((a+b)+(c-d+f))" ;
   // char s[] = "()(" ;
    cout << isValidExp(s) ;

}