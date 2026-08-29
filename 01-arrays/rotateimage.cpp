#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    //anticlockwise
    // for(int row=0;row<n;row++){
    //     // for(int col=0;col<n/2;col++){
    //     //     swap(a[row][col],a[row][n-1-col]);
    //     // }
    //     reverse(a[row],a[row]+n);
    // }
    // for(int row=0;row<n;row++){
    //     for(int col=row+1;col<n;col++){
    //         swap(a[row][col],a[col][row]);
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<a[i][j]<<"    ";
    //     }
    //     cout<<endl;
    // }
    //clockwise
    for(int row=0;row<n;row++){
        for(int col=row+1;col<n;col++){
            swap(a[row][col],a[col][row]);
        }
    }
    for(int row=0;row<n;row++){
        // for(int col=0;col<n/2;col++){
        //     swap(a[row][col],a[row][n-1-col]);
        // }
        reverse(a[row],a[row]+n);
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<"    ";
        }
        cout<<endl;
    }

}