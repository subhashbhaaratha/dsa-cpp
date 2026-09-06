#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main() {
		int n;
		cin>>n;
		int a[n];
        int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
            sum+=a[i];
		}
		int smallest=INT_MAX;
        int current_minsum=0;
		for(int i=0;i<n;i++)
        {
            current_minsum=min(current_minsum+a[i],a[i]);
            smallest=min(smallest,current_minsum);
        
        }
        int largest=INT_MIN;
        int current_maxsum=0;
		for(int i=0;i<n;i++)
        {
            current_maxsum=max(current_maxsum+a[i],a[i]);
            largest=max(largest,current_maxsum);
        
        }
        if(largest<0)
        cout<<largest<<endl;
        else
        cout<<max(sum-smallest,largest);


	return 0;
}