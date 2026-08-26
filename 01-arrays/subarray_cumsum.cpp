#include<iostream>
#include<climits>
using namespace std;
int main(){
     int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int prefix[n+1];
    prefix[0]=0;
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+a[i-1];
    }
     int max_sum=INT_MIN;
    for(int i=0;i<n;i++){
        
        for(int j=i;j<n;j++){
           int  current_sum=prefix[j+1]-prefix[i];
            if(current_sum>max_sum)
            max_sum=current_sum;
        }
    }
    cout<<max_sum;
    //cumulative method
    // int cum[n];
    // cum[0]=a[0];
    // for(int i=1;i<n;i++){
    //     cum[i]=cum[i-1]+a[i];
    // }
   
    // int max_sum=INT_MIN;
    
    // for(int i=0;i<n;i++){
    //     int current_sum=0;
    //     for(int j=i;j<n;j++){
    //         if(i==0)
    //         current_sum=cum[j];
    //     else
    //         current_sum=cum[j]-cum[i-1];
    //         if(current_sum>max_sum)
    //         max_sum=current_sum;
    //     }
    // }
    // cout<<max_sum;



}