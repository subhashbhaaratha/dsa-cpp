#include<iostream>
using namespace std;
int main(){

    int N,ans=0;
    cin>>N;
    int a[3]={2,3,5};
    for(int i=1;i<8;i++)
    {
        int j=0,prd=1,count=0,temp=i;
        while(temp>0)
        {
            if((temp&1)==1)
            {
                prd*=a[j];
                count++;
            }
            j++;
            temp>>=1;
        }
        if(count%2==1)
        ans+=(N/prd);
        else
        ans-=(N/prd);

    }
    cout<<ans;



}


