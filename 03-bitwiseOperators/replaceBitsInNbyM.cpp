#include<iostream>
using namespace std;
int main(){
    long long N;
    cin>>N;
    long long M;
    cin>>M;
    int i,j;
    cin>>i>>j;
    int num=N&((-1<<(j+1))|((1<<i)-1));
    int ans=num|(M<<i);
    cout<<ans;
}