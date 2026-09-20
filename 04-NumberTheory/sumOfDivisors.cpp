#include <iostream>
#include<vector>
using namespace std;
int product(int n,int count){
   int sum=0,p=1;
    for(int i=0;i<=count;i++){
        sum+=p;
        p=p*n;
    }
    return sum;
}
int main()
{
    int n,count,ans=1;
    cin >> n;
   
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i==0)
        {
            count=0;
            while (n % i == 0)
            {
                n = n / i;
                count++;
            }
            ans=ans*(product(i,count));
        }
    }
    if(n>1){
         ans=ans*(product(n,1));
    }
    cout<<ans;
    
}