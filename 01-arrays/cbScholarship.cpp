#include<iostream>
using namespace std;
bool isPossibleScholarship(int n,int m,int x,int y,int max_scholar){
    if(max_scholar*x<=m+(n-max_scholar)*y){
        return true;
    }
    else
    return false;
}
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int s=0,e=n,ans;
    while(s<=e){
        int mid=s+(e-s)/2;
        bool isPossible=isPossibleScholarship(n,m,x,y,mid);
        if(isPossible){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<ans;
}