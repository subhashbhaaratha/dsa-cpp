#include<iostream>
using namespace std;
int main()
{
    int a,b,m;
    cin>>a>>b>>m;
    a=a%m;
    int ans=1;
    while(b>0)
    {
        if(b&1==1)
        {
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
    }
    cout<<ans;
}