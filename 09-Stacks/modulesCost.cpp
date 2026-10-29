#include<iostream>
#include<stack>
using namespace std ;
int main()
{
    int q ;
    cin >> q ;
    stack<int> s ;
    while(q--)
    {
        
        int type ;
        cin >> type ;
        if(type == 2)
        {
            int cost ;
            cin >> cost ;
            s.push(cost) ;
        }
        else
        {
            if(!s.empty())
            {
                cout << s.top() << endl ;
                s.pop() ;

            }
            else
            {
                cout << "No Code" << endl ;
            }
        }
    }
}