#include<iostream>
#include<algorithm>
using namespace std;
int multiplier(int a){
    int m=1;
    while(a>=1){
        a=a/10;
        m*=10;
    }
    return m;
}
bool compare(int a,int b){
    int value1;
    int value2;
    value1=a*multiplier(b)+b;
    value2=b*multiplier(a)+a;
    return value1>value2;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,compare);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }


}