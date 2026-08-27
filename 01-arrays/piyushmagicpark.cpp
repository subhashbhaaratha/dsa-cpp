#include <iostream>
using namespace std;
int main()
{
    int m,n,k,s;
    cin>>m>>n>>k>>s;
    char a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    bool success=true;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
             if(s<k){
                success=false;
                break;
            }
            if(a[i][j]=='.'){
                s=s-2;
            }
            else if(a[i][j]=='*'){
                s=s+5;
            }
            else if(a[i][j]=='#')
            {
                break;
            }
            if(s<k){
                success=false;
                break;
            }
           
            if(j!=n-1)
            s=s-1;
        
       
        }
        if(!success)
        break;
    }
    if(success){
        cout<<"Yes"<<" "<<s;
    }
    else
    {
        cout<<"No";
    }

}