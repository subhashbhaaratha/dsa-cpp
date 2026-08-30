#include<iostream>
#include<string>
using namespace std;
int main(){
    string s0;
    string s1("Hello");
    string s2="Hello World";
    string s3(s2);
    cout<<s3<<endl;
    string s4=s3;
    cout<<s4<<endl;
    char a[]={'a','b','c','\0'};
    string s5(a);
    cout<<s5<<endl;
    if(s0.empty())
    cout<<"s0 string is empty"<<endl;
    s0.append("I love C++");
    cout<<s0<<endl;
    s0+=" and python";
    cout<<s0<<endl;
    cout<<s0.length()<<endl;
    s0.clear();
    cout<<s0.length()<<endl;
    s0="Apple";
    s1="Mango";
    cout<<s1.compare(s0)<<endl;
    cout<<s0.compare(s1)<<endl;
    if(s1>s0){
        cout<<"Mango is lexicographically greater than Apple"<<endl;
    }
    cout<<s1[0]<<endl;
    string s="I want to have apple juice";
   int idx = s.find("apple");
   cout<<idx<<endl;
    string word("apple");
    int len=word.length();
    s.erase(idx,len+1);
    cout<<s<<endl;
    for(int i=0;i<s.length();i++){
        cout<<s[i]<<":";
    }
    cout<<endl;
    for(auto it=s.begin();it!=s.end();it++){
        cout<<*it<<":";
    }

    cout<<endl;
    for(char c:s){
        cout<<c<<",";
    }

}