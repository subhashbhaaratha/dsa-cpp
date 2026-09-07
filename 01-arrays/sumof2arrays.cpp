#include <iostream>
#include <algorithm>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int a[2000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    int b[2000];
    for (int i = 0; i < m; i++)
        cin>>b[i];
    int c[2000];
    reverse(a, a + n);
    reverse(b, b + m);
    int carry = 0;
    for (int i = 0; i < max(n, m); i++)
    {

        int x=0;
        int y=0;
        if(i<n)
        x=a[i];
        if(i<m)
        y=b[i]; 
       c[i]=(x+y+carry)%10;
       carry=(x+y+carry)/10;
    }
    int size=max(n,m);
    if(carry)
    {
        c[size]=carry;
        size++;

    }    
        for (int i = size-1; i >= 0; i--)
        {
            cout << c[i] << ", ";
        }
    
   
    cout << "END";
    return 0;
}