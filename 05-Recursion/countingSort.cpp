#include<iostream>
using namespace std;
// void counting_sort(int *a,int n)
// {
//     int largestidx=max_element(a,a+n)-a;
//     int largest=a[largestidx];
//     int freq[1000]={0};
//     for(int i=0;i<n;i++)
//     {
//         freq[a[i]]++;
//     }
   
//     for(int i=0;i<=largest;i++)
//     {
//         while(freq[i]--)
//         {
//             cout<<i<<" ";
//         }
//     }
// }
void counting_sort2(int *a,int n)
{
    int largest=-1;
    for(int i=0;i<n;i++)
    largest=max(a[i],largest);
    int *freq=new int[largest+1]{0};
    for(int i=0;i<n;i++)
    {
        freq[a[i]]++;
    }
    int j=0;
    for(int i=0;i<=largest;i++)
    {
        while(freq[i])
        {
            a[j]=i;
            j++;
            freq[i]--;
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
    counting_sort2(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<",";

}