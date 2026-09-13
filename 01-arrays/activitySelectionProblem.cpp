#include <iostream>
#include <algorithm>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}
int main()
{
    int n;
    cin>>n;
    pair<int,int>p[n];
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n,compare);
    int count=1;
    int last_finish=p[0].second;
    for(int i=1;i<n;i++){
        if(p[i].first>=last_finish){
            count++;
            last_finish=p[i].second;
        }
    }
    cout<<count;




}