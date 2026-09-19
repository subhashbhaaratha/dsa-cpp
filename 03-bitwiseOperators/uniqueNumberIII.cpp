#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> arr(64);
    for (long long i = 0; i < n; i++)
    {
        long long j=0;
        while (a[i] > 0)
        {
            arr[j]+=(a[i]&1);
           a[i]= a[i]>>1;
            j++;
        }
    }
    long long ans=0,p=1;
    for(int i=0;i<64;i++){
        arr[i]=arr[i]%3;
        ans+=p*arr[i];
        p=p*2;
    }
    cout<<ans;
    
}