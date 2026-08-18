#include<iostream>
#include<climits>
using namespace std;
int main(){

    int N;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    int largest=INT_MIN;
    int smallest=INT_MAX;
    for(int i=0;i<N;i++){
        if(a[i]>largest){
            largest=a[i];
        }
        if(a[i]<smallest){
            smallest=a[i];
        }
    }
    cout<<"largest:"<<largest<<endl;
    cout<<"smallest:"<<smallest<<endl;




    return 0;
}