#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int prev = a[0];
    int prev_idx = 0;
    int water = 0;
    int temp = 0;
    for (int i = 1; i < n; i++)
    {

        if (a[i] >= prev)
        {
            water += temp;
            temp = 0;
            prev = a[i];
            prev_idx = i;
        }
        else
        {
            temp += prev - a[i];
        }
    }

    int rightWall = a[n - 1];
    for (int i = n - 2; i >= prev_idx; i--)
    {
        if (a[i] >= rightWall)
        {
            rightWall = a[i];
        }
        else
        {
            water += rightWall - a[i];
        }
    }
    cout << water;
}