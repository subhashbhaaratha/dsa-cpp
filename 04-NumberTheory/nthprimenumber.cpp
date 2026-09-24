#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=10000000;
int p[MAXN];
int primesieve(int n)
{
    for(long long i=3;i<MAXN;i+=2)
    {
        p[i]=1;
    }
    for(long long i=3;1LL*i*i<=MAXN;i+=2)
    {
        if(p[i]==1)
        {
            for(long long j=1LL*i*i;j<=MAXN;j+=1LL*2*i)
            {
                p[j]=0;
            }
        }
    }

    p[2]=1;
    if(n==1)
    return 2;
    int count=1;
    for(long long i=3;i<=MAXN;i++)
    {
        if(p[i]==1)
        {
           count++;
        }
        if(count==n)
        return i;
    }
    return -1;

}
int main()
{
    int n;
    cin>>n;
   cout<<primesieve(n);
   return 0;
    
}