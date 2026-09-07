#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[2000];
	int temp=n;
	int elementcount=0;
	while(temp>0){
		a[elementcount]=temp%10;
		temp=temp/10;
		elementcount++;
	}
	while(--n){
		int carry=0;
		for(int i=0;i<elementcount;i++){
			int value=a[i]*n +carry;
			a[i]=value%10;
			carry=value/10;
			
		}
		while(carry>0){
			a[elementcount++]=carry%10;
			carry/=10;
		}
		
	}
	for(int i=elementcount-1;i>=0;i--){
		cout<<a[i];
	}
	
	
	
	return 0;
}