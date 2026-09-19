#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;
    //first Method O(logN)
    // while(n>0){
    //     ans+=n&1;
    //     n=n>>1;
    // }
    // cout<<ans;
    // //second Method O(no of set bits)
    // while(n>0){
    //     n=n&(n-1);
    //     ans++;
    // }
    // cout<<ans;
    //third method
    cout<<__builtin_popcount(n);
}