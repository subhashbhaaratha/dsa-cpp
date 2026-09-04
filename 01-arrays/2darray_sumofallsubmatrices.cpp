#include <iostream>
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
    // int sum=0;

    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         for(int k=i;k<m;k++){
    //             for(int l=j;l<n;l++){
    //                 for(int p=i;p<=k;p++){
    //                     for(int q=j;q<=l;q++){
    //                         sum+=a[p][q];
    //                     }
    //                 }

    //             }
    //         }
    //     }
    // }
    // cout<<sum;

    // 2nd approach
    //    long long  prefix[101][101]={};

    //    for(int i=1;i<m+1;i++){
    //     for(int j=1;j<n+1;j++){
    //         prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+a[i-1][j-1];
    //     }
    //    }

    //    long long sum=0;
    //    for(int li=0;li<m;li++){
    //     for(int lj=0;lj<n;lj++){
    //         for(int bi=li;bi<m;bi++){
    //             for(int bj=lj;bj<n;bj++){
    //                 sum+=prefix[bi+1][bj+1]-prefix[li][bj+1]-prefix[bi+1][lj]+prefix[li][lj];
    //             }
    //         }
    //     }
    //    }
    //    cout<<sum;
    // 3rd approach
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j] * (i + 1) * (j + 1) * (m - i) * (n - j);
        }
    }

    cout << sum;

    return 0;
}