
#include <iostream>
#include <algorithm>
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
    int target;
    cin >> target;
    sort(a, a + n);

    int left = 0, right = n - 1;
    while (left < right)
    {
        if (a[left] + a[right] < target)
        {
            left++;
        }
        else if (a[left] + a[right] > target)
        {
            right--;
        }
        else
        {
            cout<<a[left]<<" and "<<a[right]<<endl;
            int leftValue=a[left];
            int rightValue=a[right];
            while(left<right && a[left]==leftValue){
                left++;
            }
            while(left<right&& a[right]==rightValue){
                right--;
            }
        }
    }
}