#include<iostream>
using namespace std;
void permute(char*in,int i)
{
    if(in[i]=='\0')
    {
        cout<<in<<", ";
        return;
    }
    bool tried[256]={false};
    for(int j=i;in[j]!='\0';j++)
    {
       char ch=in[j];
        if(tried[ch])
        continue;
        tried[ch]=true;
        swap(in[i],in[j]);
        permute(in,i+1);
        swap(in[i],in[j]);
    }
}
int main()
{
    char in[100];
    cin>>in;
    permute(in,0);
}