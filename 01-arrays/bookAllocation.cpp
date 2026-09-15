#include<iostream>
using namespace std;
bool canWeAllocate(int pages[],int n,int m,int max_pages){
    int studentsUsed=1;
    int pagesreading=0;
    for(int i=0;i<n;i++){
        if(pagesreading+pages[i]<=max_pages){
            pagesreading+=pages[i];
        }
        else{
            studentsUsed++;
            pagesreading=pages[i];
            if(studentsUsed>m)
            return false;
        }
    }
    return true;
} 


int main(){
    int n,m;
    cin>>n>>m;
    int pages[1000],sum=0,s=0;
    for(int i=0;i<n;i++){
        cin>>pages[i];
        sum+=pages[i];
        s=max(s,pages[i]);
    }
    int e=sum;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        bool isPossible=canWeAllocate(pages,n,m,mid);
        if(isPossible)
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    cout<<ans;
    
}