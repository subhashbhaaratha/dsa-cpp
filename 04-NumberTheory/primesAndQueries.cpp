#include<iostream>
using namespace std;
void primeSeive(int p[]){
    for(long long i=3;i<1000000;i+=2)
    {
        p[i]=1;
    }
     for(long long i=3;1LL*i*i<1000000;i+=2)
    {
       if(p[i]==1)
       {
        for(long long  j=1LL*i*i;j<1000000;j+=1LL*2*i)
        {
            p[j]=0;
        }
       }
    }
    p[0]=0;
    p[1]=0;
    p[2]=1;
}
int main(){
    int primes[1000000]={0};
    primeSeive(primes);
    int prefix[1000001];
    prefix[0]=0;
    for(long long i=1;i<=1000000;i++){
        prefix[i]=prefix[i-1]+primes[i-1];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<prefix[b+1]-prefix[a]<<endl;
    }

}