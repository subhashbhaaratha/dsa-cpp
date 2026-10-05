#include<iostream>
using namespace std;
void permute(char* in,char* out ,bool* used ,int i,int n)
{
    if(i==n)
    {
        out[i]='\0';
        cout<<out<<",";
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(used[j]==false)
        {
            out[i]=in[j];
            used[j]=true;
            permute(in,out,used,i+1,n);
             used[j]=false;
        }
       
    }
}
int main()
{
    char in[100];
    cin>>in;
    char out[100];
    bool used[100]={false};
    int n=strlen(in);
    permute(in,out,used,0,n);
}