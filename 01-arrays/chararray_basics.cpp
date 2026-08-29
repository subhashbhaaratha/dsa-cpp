#include <iostream>
using namespace std;
void readline(char a[],int maxLen , char delim){
    int i=0;
    char ch=cin.get();
    while(ch!=delim){
        a[i]=ch;
        i++;
        if(i==maxLen-1)
        break;
        ch=cin.get();
    }
    a[i]='\0';

}
int main()
{
    // int b[] = {1, 2, 3};
    // cout << b << endl;
    // char c[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    // char a[] = {'h', 'e', 'l', 'l', 'o'};

    // cout << a << " " << sizeof(a) << endl;
    // cout << c << " " << sizeof(c) << endl;
    // char s4[10];
    // cin>>s4;
    // cout<<s4;
    char s4[100];
    readline(s4,100,'$');
    cout<<s4;
    
    
}