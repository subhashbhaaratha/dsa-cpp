#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int ans=1;
    while(b>0){
        int last_bit=b&1;
        if(last_bit==1){
            ans=ans*a;
        }
        a=a*a;
        b=b>>1;
    }
    cout<<ans;

}