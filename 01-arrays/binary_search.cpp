#include<iostream>
using namespace std;

int binary_search(int a[],int n,int key){
    int s=0 , e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]>key){
            e=mid-1;
        }
        else if(a[mid]<key){
            s=mid+1;
        }
        else
        return mid;
    }
   return -1;

}


int main(){ 
    int n,key,flag=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<"enter the number you want to search:";
    cin>>key;
   int ans= binary_search(a,n,key);
   if(ans==-1)
   cout<<"Number not found";
else
cout<<ans;

}