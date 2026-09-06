#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int incleft[n];
    int incright[n];
    incleft[0]=1;
    for(int i=1;i<n;i++){
        if(a[i-1]<=a[i])
        incleft[i]=incleft[i-1]+1;
        else
        incleft[i]=1;
    }
    incright[n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(a[i+1]<=a[i])
        incright[i]=incright[i+1]+1;
        else
        incright[i]=1;
    }
    int largest=INT_MIN;
    int value;
    for(int i=0;i<n;i++){
        value=incleft[i]+incright[i]-1;
        largest=max(largest,value);
    }
    cout<<largest<<endl;
	}

}