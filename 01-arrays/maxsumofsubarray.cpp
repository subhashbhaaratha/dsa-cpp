#include <iostream>
#include<algorithm>
#include <climits>
using namespace std;
int main()
{
    int a[100][100];
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    long long suffix[101][101]={};
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            suffix[i][j]=suffix[i][j+1]+suffix[i+1][j]-suffix[i+1][j+1]+a[i][j];
        }
    }
    long long largest=LLONG_MIN;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            largest=max(largest,suffix[i][j]);
        }
    }
cout<<largest;
}