#include <iostream>
using namespace std;
int lastOcc(int *a,int n,int key,int i)
{
   if(i==n)
   return -1;
   int ans=lastOcc(a,n,key,i+1);
   if(ans!=-1)
    return ans;
    if(a[i]==key)
    return i;

    return -1;
}
int lastOccur(int *a,int n,int key)
{
    if(n==0)
    return -1;
    int i=lastOccur(a+1,n-1,key);
    if(i==-1)
    {
        if(a[0]==key)
        return 0;
        else
        return -1;
    }
    return i+1;
}

int main()
{
    int arr[]={1,2,3,7,8,6,7,5};
    int n=sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    cout<<lastOcc(arr,n,key,0);
    cout<<endl<<lastOccur(arr,n,key);
    
}