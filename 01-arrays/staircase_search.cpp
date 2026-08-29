#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int key;
    cin >> key;

    // basic approach O(n2)
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (a[i][j] == key)
    //         {
    //             cout << i << " " << j;
    //             return 0;
    //         }
    //     }

    // }

    //     cout << "number not found";
    //     return 0;
    // binary search approach O(nlogn)
    // for(int row=0;row<n;row++){
    //     int s=0,e=n-1;
    //     while(s<=e){
    //         int mid=(s+e)/2;
    //         if(a[row][mid]<key)
    //         s=mid+1;
    //         else if(a[row][mid]>key)
    //         e=mid-1;
    //         else{
    //         cout<<row<<" "<<mid ;
    //         return 0;
    //         }
    //     }
    // }
    // O(N)method
    int i = 0, j = n - 1;
    while (i <= n - 1 && j >= 0)
    {
        if (a[i][j] < key)
        {
            i++;
        }
        else if (a[i][j] > key)
        {
            j--;
        }
        else
        {
            cout << i << " " << j;
            return 0;
        }
    }
}