#include <iostream>
#include<algorithm>
using namespace std;
// int gcdOfTwoNumbers(int a,int b){
//     if(b==0)
//     return a;
//     return gcdOfTwoNumbers(b,a%b);
    
// }
int gcdOfTwoNumbers(int a,int b){
    while(b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
    
}
int lcmOfTwoNumbers(int a,int b){
   int larger=max(a,b);
   int smaller=min(a,b);
   for(int value=larger;;value+=larger)
   {
    if(value%smaller==0)
    return value;
   }
}
int main(){
    int a,b;
    cin>>a>>b;
   
    int gcd=gcdOfTwoNumbers(a,b);
    cout<<gcd;
    // int lcm=(a*b)/gcd;
    // cout<<" "<<lcm;
    cout<<" "<<lcmOfTwoNumbers(a,b);
}