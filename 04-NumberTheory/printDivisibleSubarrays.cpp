#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[10000];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int prefix[100001];
    prefix[0]=0;
    for(int i=1;i<=n;i++)
    {
        prefix[i]=prefix[i-1]+a[i-1];
    }
  
    for(int i=0;i<=n;i++)
    {
        prefix[i]=(prefix[i])%n;
        
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(prefix[i]==prefix[j])
            {
                for(int k=i;k<=j-1;k++)
                cout<<a[k]<<" ";
                cout<<endl;
            }
            
        }
    }

   

}