#include<iostream>
using namespace std;

bool isOdd(int n){
    return n&1;
}
int getBit(int n,int i){
    int mask=1<<i;
    int bit=(n&mask)>0?1:0;
    return bit ;
    
}
int setBit(int n,int i){
    int mask=1<<i;
    int bit=n|mask;
    return bit;
}
int clearBit(int n,int i){
    int mask=~(1<<i);
    int bit=n&mask;
    return bit;

}
int updateBit(int n,int i,int v ){
    int mask=~(1<<i);
    int cleared_bit_no=n&mask;
    int mask2=(v<<i);
    int ans=cleared_bit_no|mask2;
    return ans;

}
int clearIBitsFromRight(int n,int i){
    int mask=(-1<<i);
    int bit=n&mask;
    return bit;
}
int clearRangeItoJ(int n,int i,int j){
    int a=-1<<(j+1);
    int b=(1<<i)-1;
    int mask=a|b;
    int bit=n&mask;
    return bit;
}
int main(){
    int n=5;
    int i,v,j;
    cin>>i>>j;
    cout<<clearRangeItoJ(n,i,j);
    // cout<<clearIBitsFromRight(n,i);
    // cout<<updateBit(n,i,v);
    // cout<<clearBit(n,i);
    // cout<<setBit(n,i);
    // cout<<getBit(n,i);
    // cout<<isOdd(i);

}