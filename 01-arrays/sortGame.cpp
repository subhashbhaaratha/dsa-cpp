#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<string,int>p1,pair<string,int>p2){
    if(p1.second==p2.second)
    return p1.first<p2.first;

    return p1.second>p2.second;
}
int main(){
    int x,n;
    cin>>x>>n;
    vector<pair<string,int>>p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
    }
    cout<<endl;
    sort(p.begin(),p.end(),compare);
    for(int i=0;i<n;i++){
        if(p[i].second<x)
        break;
        else{
            cout<<p[i].first<<" "<<p[i].second<<endl;
        }
    }

}