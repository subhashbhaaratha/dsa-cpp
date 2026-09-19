#include <iostream>
#include <vector>
using namespace std;
int countsetbits(int n){
    int count=0;
    while(n>0){
        n=n&(n-1);
        count++;

    }
    return count;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,ans=0;
        cin>>a>>b;
        for(int i=a;i<=b;i++)
        ans+=countsetbits(i);
        cout<<ans<<endl;

    }
}
