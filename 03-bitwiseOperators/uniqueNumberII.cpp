#include <iostream>
#include <vector>
using namespace std;

int findFirstSetBitIdx(int n)
{
    int count = 0;
    while (1)
    {
        if ((n & 1) == 1)
        {
            return count;
        }
        n=n>>1;
        count++;
    }
}
bool setBitAt(int n, int idx)
{
    if ((n & (1 << idx)) > 0)
        return true;
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int two_xor = a[0];
    for (int i = 1; i < n; i++)
    {
        two_xor = two_xor ^ a[i];
    }
    int first_setbit_idx = findFirstSetBitIdx(two_xor);
    int num1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (setBitAt(a[i], first_setbit_idx))
        {
            num1 = num1 ^ a[i];
        }
    }
    int num2=num1^two_xor;
    cout<<num1<<" "<<num2;

    
}