#include<iostream>
#include<algorithm>
using namespace std;
void dnf_sort(int *a,int n)
{
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a[mid],a[low]);
            low++;
            mid++;
        }
        else if(a[mid]==1)
        {
            mid++;
        }
        else 
        {
            swap(a[mid],a[high]);
            high--;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    cin>>a[i];
    dnf_sort(a,n);
     for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}