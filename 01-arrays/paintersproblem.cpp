#include<iostream>
using namespace std;
bool canPaint(int boards[],int n,int k,int min_time){
    int paintersUsed=1;
    int lengthPainted=0;
    for(int i=0;i<n;i++){
        if(lengthPainted+boards[i]<=min_time){
            lengthPainted+=boards[i];
        }
        else{
            paintersUsed++;
            if(paintersUsed>k)
            return false;
            if(boards[i]>min_time)
            return false;
            else{
                lengthPainted=boards[i];
            }
        }
    }
    return true;

}
int main(){
    int k,n;
    cin>>k>>n;
    int boards[1000],e=0;
    for(int i=0;i<n;i++){
    cin>>boards[i];
    e+=boards[i];
    }
    
    int s=0,ans;
    while(s<=e){
        int mid=s+(e-s)/2;
        bool isPossible=canPaint(boards,n,k,mid);
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