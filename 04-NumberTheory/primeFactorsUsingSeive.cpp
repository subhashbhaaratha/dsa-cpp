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
void factorise(int n,vector<int>&primes){
    int count;
    vector<pair<int,int>>factors;
   for(auto p:primes){
     
        count=0;
        if(p*p>n)
        break;
        while(n%p==0){
            n=n/p;
            count++;
        }
        if(count>0)
        {
            factors.push_back(make_pair(p,count));
        }
    
   }
   if(n>0)
   factors.push_back(make_pair(n,1));
   for(auto p:factors){
    cout<<p.first<<"^"<<p.second<<endl;
   }
}

int main(){
    int n;
    cin>>n;
    
    int p[1000005]={0};
   vector<int>primes=primeSeive(p,n);
    factorise(n,primes);


}