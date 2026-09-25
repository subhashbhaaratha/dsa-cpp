#include <iostream>
using namespace std;
void allOccu(int *a,int i,int n,int key)
{
    if(i==n)
    return;
    if(a[i]==key)
    cout<<i<<",";
     allOccu(a,i+1,n,key);

    
}
int storeOccu(int *a,int i,int n,int key,int *out,int j)
{
    if(i==n)
    return j;
    if(a[i]==key)
    {
        out[j]=i;
        return storeOccu(a,i+1,n,key,out,j+1);
    }
   return storeOccu(a,i+1,n,key,out,j);

}

int main()
{
    int arr[]={1,2,3,7,8,6,7,5};
    int n=sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    allOccu(arr,0,n,key);
    cout<<endl;
    int output[100];
    int count=storeOccu(arr,0,n,key,output,0);
    for(int i=0;i<count;i++)
    cout<<output[i]<<" ";
    
    
}