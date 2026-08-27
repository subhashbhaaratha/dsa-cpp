//red
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"Enter sum:";
    int sum;
    cin>>sum;
    //basic approach
    // for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(a[i]+a[j]==sum)
    //         {
    //             cout<<a[i]<<","<<a[j]<<endl;
                
    //         }
    //     }
    // }

    //binary search approach

    // for(int i=0;i<n-1;i++){
    //     int s=i+1;
    //     int e=n-1;
    //     while(s<=e){
    //         int mid=(s+e)/2;
    //         if((sum-a[i])<a[mid]){
    //             e=mid-1;
    //         }
    //         else if((sum-a[i])>a[mid])
    //         s=mid+1;
    //         else
    //         {
    //             cout<<a[i]<<","<<a[mid]<<endl;
    //             break;
    //         }

   
    // }

    //two pointer approach
    int i=0;
    int j=n-1;
    while(i<j){
        if((a[i]+a[j])==sum)
        {
            cout<<a[i]<<","<<a[j]<<endl;
            i++;
            j--;
        }
        else if((a[i]+a[j])>sum)
        {
            j--;
        }
        else
        i++;
    }
    //what if numbers are repeating 111555 sum is 6?output cant be 1,5 ;1,5;1,5;

}