#include <iostream>
using namespace std;
void primeSeive(int p[])
{
    for (int i = 3; i <= 1000000; i += 2)
    {
        p[i] = 1;
    }
    for (long long i = 3; i <= 1000000; i += 2)
    {
        if (p[i] == 1)
        {
            for (long long j = 1LL*i * i; j <= 1000000; j += i)
            {
                p[j] = 0;
            }
        }
    }
    p[1] = 0;
    p[2] = 1;
}
int main()
{
    int n;
    cin >> n;
    int primes[1000005] = {0};
    primeSeive(primes);
    for (int i = 1; i <= n; i++)
    {
        if (primes[i] == 1)
            cout << i << " ";
    }
}