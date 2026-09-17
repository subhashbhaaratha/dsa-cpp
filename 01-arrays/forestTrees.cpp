#include<iostream>
using namespace std;
bool canGetWood(int trees[],int n,int m,int height_given){
    int sum=0;
    for(int i=0;i<n;i++){
        if((trees[i]-height_given)>=0)
        sum+=trees[i]-height_given;
        
        if(sum>=m)
        return true;
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    int trees[n],s=0,e=0;
    for(int i=0;i<n;i++){
        cin>>trees[i];
        e=max(e,trees[i]);
    }
    int ans;
    while(s<=e){
        int mid=(s+e)/2;
        bool isPossible=canGetWood(trees,n,m,mid);
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