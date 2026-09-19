#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int n0;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>n0;
        ans=ans^n0;
    }
    cout<<ans<<endl;
}