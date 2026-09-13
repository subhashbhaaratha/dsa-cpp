#include<iostream>
using namespace std;
float square_root(int n){
    int start=0,end=n;
    float ans;
    while(start<=end){
        int mid=(start+end)/2;
        if(mid*mid==n)
        return mid;
        else if(mid*mid<n){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    float inc=0.1;
    for(int i=1;i<=3;i++){
        while(ans*ans<=n){
            ans=ans+inc;
        }
        ans=ans-inc;
        inc=inc/10;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<square_root(n);
}