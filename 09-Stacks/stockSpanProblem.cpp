#include<iostream>
#include<stack>
using namespace std ;
void stockSpan(int prices[], int n, int span[])
{
    stack<int> s ;
    for(int i = 0 ; i < n ; i++)
    {
        while(!s.empty() && prices[i] > prices[s.top()])
        {
            s.pop() ;
        }
        if(s.empty())
        {
            span[i] = i + 1 ; 
        }
        else
        {
            span[i] = i - s.top() ;
        }
        s.push(i) ;
    }
}



int main()
{
    int prices[] = {100, 80, 60, 70, 60, 75, 85} ;
    int n = sizeof(prices) / sizeof(int) ;
    int span[1000] = {0} ;
    stockSpan(prices, n, span) ;
    for(int i = 0 ; i < n ; i++)
    {
        cout << span[i] << " " ;
    }
}