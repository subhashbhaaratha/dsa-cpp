#include<iostream>
using namespace std;
int profits(int n,int c,int* weights,int* prices)
{
    if(n==0||c==0)
    return 0;
    int ans=0;
    int inc,exc;
    inc=exc=0;
    if(weights[n-1]<=c)
    {
        inc=prices[n-1]+profits(n-1,c-weights[n-1],weights,prices);
    }
    exc=profits(n-1,c,weights,prices);
    ans=max(inc,exc);
    return ans;
}
int main()
{
    int weights[]={1,2,3,5};
    int prices[]={40,20,30,100};
    int n=4,c=7;
    cout<<profits(n,c,weights,prices);

}