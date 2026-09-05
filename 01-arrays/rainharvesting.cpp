#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    int leftMax[n];
    int rightMax[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int units = 0;
    leftMax[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], a[i]);
    }
    rightMax[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], a[i]);
    }

    for (int i = 0; i < n; i++)
    {

        units += min(leftMax[i], rightMax[i]) - a[i];
    }

    cout << units;
}