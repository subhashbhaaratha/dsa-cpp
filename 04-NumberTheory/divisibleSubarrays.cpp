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
    vector<int>freq(n);
    for(int i=0;i<=n;i++)
    {
        prefix[i]=(prefix[i])%n;
        freq[prefix[i]]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(freq[i]>=2)
        {
            ans+=(freq[i])*(freq[i]-1)/2;
        }
    }
    cout<<ans;



}