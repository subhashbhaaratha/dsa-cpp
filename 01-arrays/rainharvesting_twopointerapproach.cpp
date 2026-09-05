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
    int left = 0;
    int right = n - 1;
    int leftMax = 0;
    int rightMax = 0;
    int water = 0;
    while (left <= right)
    {
        if (leftMax <= rightMax)
        {
            leftMax = max(leftMax, a[left]);
            water += leftMax - a[left];
            left++;
        }
        else
        {
            rightMax = max(rightMax, a[right]);
            water += rightMax - a[right];
            right--;
        }
    }
    cout << water;
}