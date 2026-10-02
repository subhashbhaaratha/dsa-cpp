#include<iostream>
using namespace std;

void replacePi2(char *a,int i)
{
    if(a[i+1]=='\0')
    return;
    replacePi2(a,i+1);
    if(a[i]=='p'&&a[i+1]=='i')
    {
        int len=strlen(a);
        for(int j=len;j>=i+2;j--)
        {
            a[j+2]=a[j];
        }
        a[i]='3';
        a[i+1]='.';
        a[i+2]='1';
        a[i+3]='4';
    }
    

}
void replacePi(char *a,int i)
{
    if(a[i+1]=='\0')
    return;
    if(a[i]=='p'&&a[i+1]=='i')
    {
        int len=strlen(a);
        for(int j=len;j>=i+2;j--)
        {
            a[j+2]=a[j];
        }
        a[i]='3';
        a[i+1]='.';
        a[i+2]='1';
        a[i+3]='4';
         replacePi(a,i+4);
    }
   else
   replacePi(a,i+1);

}
int main()
{
    char a[100];
    cin>>a;
    
    
    replacePi(a,0);
    cout<<a;    

}