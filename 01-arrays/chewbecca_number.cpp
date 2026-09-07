#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long long n;
	cin>>n;
	
	int d;
	long long m=1,new_no=0;
	while(n>=1){
		d=n%10;
		if(d>9-d&&n!=9){
			new_no+=(9-d)*m;
		}
		else{
			new_no+=d*m;
		}
		
		n=n/10;
		m=m*10;
	}
	cout<<new_no<<endl;

	return 0;
}