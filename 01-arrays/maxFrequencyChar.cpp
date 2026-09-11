#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char a[100];
	cin>>a;
	int freq[256]={0};
	char p;
	int len=strlen(a),max_count=0;
	for(int i=0;i<len;i++){
		freq[a[i]]++;
		if(freq[a[i]]>max_count)
		{
			max_count=freq[a[i]];
			p=a[i];
		}
	}
	cout<<p;

	return 0;
}