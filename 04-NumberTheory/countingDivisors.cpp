#include<iostream>
#include<vector>
using namespace std;
vector<int> primeSeive(int p[],int n)
{
    for(int i=3;i<=1000000;i+=2)
    p[i]=1;
    for(int i=3;i*i<=1000000;i+=2){
        if(p[i]==1)
        {
            for(int j=i*i;j<=1000000;j+=2*i)
            {
                p[j]=0;
            }
        }
    }
    vector<int>primes;
    primes.push_back(2);
    for(int i=3;i<=n;i++){
        if(p[i]==1)
        primes.push_back(i);
    }
    return primes;
}
void divisors(int n,vector<int>&primes){
    
   int ans=1;
   for(auto p:primes){
     
        int count=0;
        if(p*p>n)
        break;
        while(n%p==0){
            n=n/p;
            count++;
        }
        if(count>0)
        ans=ans*(count+1);
    
   }
   if(n>1)
   ans=ans*2;
   cout<<ans;
}

int main(){
    int n;
    cin>>n;
    
    int p[1000005]={0};
   vector<int>primes=primeSeive(p,n);
    divisors(n,primes);


}