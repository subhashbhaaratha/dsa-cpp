#include<iostream>
using namespace std;
int lastOccurence(int a[],int n,int key){
    int left=0;
    int right=n-1,ans;
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]<key){
            left=mid+1;
        }
        else if(a[mid]>key){
            right=mid-1;
        }
        else{
            ans=mid;
            left=mid+1;
        }

    }
    return ans;
}
int firstOccurence(int a[],int n,int key){
    int left=0;
    int right=n-1,ans=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]<key){
            left=mid+1;
        }
        else if(a[mid]>key){
            right=mid-1;
        }
        else{
            ans=mid;
            right=mid-1;
        }

    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int key;
    cin>>key;
    cout<<"Last Occurence:"<<lastOccurence(a,n,key)<<endl;
    cout<<"First Occurence:"<<firstOccurence(a,n,key);
}