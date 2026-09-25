#include<iostream>
using namespace std;

int bin_search(int a[],int s,int e,int key)
{
    if(s>e)
    return -1;
    int mid=(s+e)/2;
    if(a[mid]==key)
    return mid;
    else if(a[mid]<key)
    {
      return  bin_search(a,mid+1,e,key);
    }
    else 
    {
      return  bin_search(a,s,mid-1,key);
    }
}




int main()
{
  int arr[]={1,3,5,7,10,12};
  int n=sizeof(arr)/sizeof(int);
  int key;
  cin>>key;
  cout<<bin_search(arr,0,n-1,key);  

}
#include<iostream>
using namespace std;

int power(int a,int b)
{
    if(b==0)
    return 1;
    return a*power(a,b-1);
}

int multi_without_x(int a,int b)
{
    if(b==0)
    return 0;
   return a+multi_without_x(a,b-1);
}
int main()
{
    int a,b;
    cin>>a>>b;
   cout<< power(a,b);
   cout<<endl<<multi_without_x(a,b);
}