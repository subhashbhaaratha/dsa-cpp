#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        int min_indx=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[min_indx])
            {
                min_indx=j;
            }
        }
        swap(a[i],a[min_indx]);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    //finding smallest and largest and placing them at starting and ending respectively
    // for(int i=0;i<n/2;i++){
    //     int min_indx=i;
    //     int max_indx=n-i-1;
    //     for(int j=i;j<n-i;j++){
    //         if(a[j]<a[min_indx])
    //         {
    //             min_indx=j;
    //         }
    //         if(a[j]>a[max_indx]){
    //             max_indx=j;
    //         }
    //     }
    //     swap(a[i],a[min_indx]);
    //     swap(a[n-i-1],a[max_indx]);
    // }
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
}