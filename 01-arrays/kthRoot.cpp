#include<iostream>

using namespace std;
bool powerIsPossible(long long num,int k,long long n){
   long long ans=1;
    while(k--){
       if(num!=0&&ans>n/num)
        return false;
        
        ans*=num;
    }
    return true;
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        int k;
        cin>>k;
        long long s=0,e=n,ans;
        while(s<=e){
            long long mid=s+(e-s)/2;
            
            if(powerIsPossible(mid,k,n)){
                ans=mid;
                s=mid+1;
            }
            else
            e=mid-1;
        }
        cout<<ans<<endl;

    }
}