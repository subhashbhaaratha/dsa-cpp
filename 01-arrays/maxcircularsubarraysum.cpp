#include<iostream>
#include<climits>
using namespace std;
int main() {

	
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int largest=INT_MIN;
        int prefix[n+1];
        prefix[0]=0;
        for(int i=1;i<n+1;i++){
            prefix[i]=prefix[i-1]+a[i-1];
        }
		for(int i=0;i<n;i++){
			int count=1;
			int j=i;
			while(count<=n){
				int sum=0;
				if(count<=n-i){
					sum+=prefix[j+1]-prefix[i];
                    largest=max(sum,largest);
				}
				else{
					sum+=prefix[n]+prefix[j+1]-prefix[i];
                    largest=max(sum,largest);
				}

				j=(j+1)%n;
                count++;
			}
		}
		cout<<largest<<endl;


	return 0;
}