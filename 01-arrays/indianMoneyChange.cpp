#include<iostream>
using namespace std;
int main(){
    int coins[]={1,2,5,10,20,50,100,200,500,1000};
    int money=168,count=0;
    auto it = upper_bound(coins,coins+10,money);
    int idx=it-coins;
    for(int i=idx-1;i>=0;i--){
       count+=money/coins[i];
       money=money%coins[i];
    }
    cout<<endl<<count;
}