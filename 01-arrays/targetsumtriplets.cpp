#include <iostream>
using namespace std;
#include<algorithm>
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int target;
    cin >> target;
    sort(a, a + n);
    for (int i = 0; i <= n - 3; i++)
    {
        if(i>0&&a[i]==a[i-1]){
            continue;
        }

        int left = i + 1, right = n - 1;
        int value = target - a[i];
        while (left < right)
        {
            if (a[left] + a[right] > value)
            {
                right--;
            }
            else if (a[left] + a[right] < value)
            {
                left++;
            }
            else
            {
                cout << a[i] << ", " << a[left] << " and " << a[right] << endl;
                int leftValue = a[left];
                int rightValue = a[right];
                while (left < right && a[left] == leftValue)
                {
                    left++;
                }
                while (left < right && a[right] == rightValue)
                {
                    right--;
                }
            }
        }
        
    }
}