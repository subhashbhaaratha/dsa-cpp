#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int a[N],key;
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    cout<<"Enter the element you want to search";
    cin>>key;
    int i;
    for( i=0;i<N;i++){
        if(a[i]==key)
        {
            cout<<i<<"th index";
            break;
        }
    }
    if(i==N)
    cout<<"number not found";
}