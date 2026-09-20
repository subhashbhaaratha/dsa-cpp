#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n,count;
    cin >> n;
    vector<pair<int,int>>factors;
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
            factors.push_back(make_pair(i,count));
        }
    }
    if(n!=1){
        factors.push_back(make_pair(n,1));
    }
    for(auto p:factors)
    cout<<p.first<<"^"<<p.second<<endl;
    
}