#include<iostream>
#include<stack>
using namespace std ;
int histogramArea(int a[], int n)
{
    stack<int> s ;
    int maxArea = -1 ;
    int area = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
         
         while(!s.empty() && a[i] < a[s.top()])
         {
            int top = s.top() ;
            s.pop() ;
            if(!s.empty())
            {
                area = a[top]*(i - s.top() - 1) ;
                maxArea = max(maxArea, area) ;
            }
            else
            {
                area= a[top]*(i) ;
                maxArea = max(maxArea, area) ;
            }
        }  
        s.push(i) ; 
    }
    while(!s.empty())
    {
        int top = s.top() ;
        s.pop() ;
        if(!s.empty())
        {
            area = a[top]*(n - s.top() - 1) ;
            maxArea = max(maxArea, area) ;
        }
        else
        {
            area = a[top]*(n) ;
            maxArea = max(maxArea, area) ;
        }
        
    }
    return maxArea ;

}
int main()
{
    int a[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(a) / sizeof(int) ;
    cout <<  histogramArea(a, n) ;

}