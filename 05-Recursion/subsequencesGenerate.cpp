#include<iostream>
using namespace std;
void subsequenceGenerate(char* in,char* out,int i,int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    out[j]=in[i];
    subsequenceGenerate(in,out,i+1,j+1);
    subsequenceGenerate(in,out,i+1,j);
}
int main()
{
    char a[]={"abc"};
    char out[10];
    subsequenceGenerate(a,out,0,0);
}