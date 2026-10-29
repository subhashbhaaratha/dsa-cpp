#include<iostream>
#include<vector>
#include<stack>
using namespace std ;
const int MAXN = 1300000 ;
int p[MAXN + 1] = {0} ;
vector<int> allPrimes()
{
    for(int i = 3 ; i <=MAXN ; i+=2)
    {
        p[i] = 1 ;
    }
    for(int i = 3 ; i * i <= MAXN ; i+=2)
    {
        if(p[i] == 1)
        {
            for(int j = i * i ; j <= MAXN ; j += 2*i)
            {
                p[j] = 0 ;
            }
        }
    }
    p[2] = 1 ;
    vector<int>primes ;
    for(int i = 2 ; i <= MAXN ; i++)
    {
        if(p[i] == 1)
        {
           primes.push_back(i) ;
        }
    }
    return primes;
}
int main()
{
    int n ,q ;
    cin >> n >> q ;
    vector<int> primes = allPrimes() ;
    vector<stack<int>>a(q + 1) ;
    vector<stack<int>>b(q + 1) ;
    for(int j = 1 ; j <= n ; j++)
    {
        int n0 ;
        cin >> n0 ;
        a[0].push(n0) ;
    }
    for(int i = 1 ; i <= q ; i++)
    {
        while(!a[i - 1].empty())
        {
        if(((a[i - 1].top())%(primes[i - 1])) == 0)
        {
            b[i].push(a[i - 1].top()) ;
        }
        else
        {
            a[i].push(a[i - 1].top()) ;
        }
        a[i - 1].pop() ;
       }
    }
    for(int i = 1 ; i <= q ; i ++)
    {
        while(!b[i].empty())
        {
            cout << b[i].top() << endl ;
            b[i].pop() ;
        }
    }
    while(!a[q].empty())
    {
        cout << a[q].top() << endl ;
        a[q].pop() ;
    }
}