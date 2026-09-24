#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1000001;

vector<int> primesieve(int p[])
{
    for (int i = 3; i <= MAXN; i += 2)
    {
        p[i] = 1;
    }
    for (int i = 3; 1LL * i * i <= MAXN; i += 2)
    {
        if (p[i] == 1)
        {
            for (int j = 1LL * i * i; j <= MAXN; j += 1LL * 2 * i)
            {
                p[j] = 0;
            }
        }
    }

    p[2] = 1;
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i <= MAXN; i++)
    {
        if (p[i] == 1)
        {
            primes.push_back(i);
        }
    }
    return primes;
}
int main()
{
    int p[MAXN] = {0};
    vector<int> primes = primesieve(p);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout<<primes[n-1]<<endl;
    }

}

