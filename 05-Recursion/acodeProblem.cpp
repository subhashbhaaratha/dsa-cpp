#include<iostream>
using namespace std;
void generate_strings(char* in,char* out,int i,int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    int digit=in[i]-'0';
    if(digit==0)
    {
       
        return;
    }
    char ch=digit-1+'A';
    out[j]=ch;
    generate_strings(in,out,i+1,j+1);
    if(in[i+1]!='\0')
    {
        int secondDigit=in[i+1]-'0';

        int num=digit*10+secondDigit;
        if(num<=26)
        {
            char ch2=num-1+'A';
            out[j]=ch2;
            generate_strings(in,out,i+2,j+1);
        }
    }
    return ;
}
int main()
{
    char input[100];
    cin>>input;
    char output[100];
    generate_strings(input,output,0,0);
}