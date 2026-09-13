#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int start = 0, end = n - 1, key;
    cin >> key;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == key)
        {
            cout << mid;
            break;
        }
        else if (a[start] <= a[mid])
        {
            if (a[start] <= key && key < a[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (a[mid] < key && key <= a[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
}