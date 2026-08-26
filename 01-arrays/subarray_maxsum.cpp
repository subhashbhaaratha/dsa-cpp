#include<iostream>
using namespace std;
int main(){
     int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
int left,right;
int max_sum=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int current_sum=0;
            
            for(int k=i;k<=j;k++){
                current_sum+=a[k];
            }
            if(current_sum>max_sum){
            max_sum=current_sum;
                left=i;
                right=j;
            }
        }
    }

    cout<<"Maximum sum is:"<<max_sum;
    for(int i=left;i<=right;i++){
        cout<<a[i]<<",";
    }
}