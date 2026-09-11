#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char a[1001];
	cin>>a;
	int len=strlen(a);
	int count=0;
	for(int i=0;i<len;i++){
		if(i>0&&a[i]>='A'&&a[i]<='Z')
		{
			cout<<endl;
			
		}
		cout<<a[i];
	}
	
	
	return 0;
}
