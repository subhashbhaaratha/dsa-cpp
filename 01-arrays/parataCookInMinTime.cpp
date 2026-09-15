#include<iostream>
using namespace std;
bool canCook(int cooks[],int n,int p,int min_time){
    int paratas=0;
    for(int i=0;i<n;i++){
        int time=0,parataNo=1;
        while(time+parataNo*cooks[i]<=min_time){
            time+=parataNo*cooks[i];
            paratas++;
            if(paratas==p)
            return true;
            parataNo++;


        }

    }
    return false;
}
int main(){
    int p,n;
    cin>>p>>n;
    int cooks[1000];
    for(int i=0;i<n;i++)
    cin>>cooks[i];

    int s=0;
    int e=p*(p+1)*cooks[0]/2,ans;
    while(s<=e){
        int mid=s+(e-s)/2;
        bool isPossible=canCook(cooks,n,p,mid);
        if(isPossible){
            ans=mid;
            e=mid-1;

        }
        else{
            s=mid+1;
        }
    }
    cout<<ans;
}