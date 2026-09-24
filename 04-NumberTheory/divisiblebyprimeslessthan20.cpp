#include<iostream>
using namespace std;
int main(){

    int N,ans=0;
    cin>>N;
    int a[]={2,3,5,7,11,13,17,19};
    for(int i=1;i<(1<<8);i++)
    {
        int prd=1;
        int setbits=__builtin_popcount(i);
       for(int j=0;j<=7;j++)
       {
        if(i&(1<<j))
        prd*=a[j];

       }


        if(setbits&1)
        ans+=(N/prd);
        else
        ans-=(N/prd);

    }
    cout<<ans;



}


