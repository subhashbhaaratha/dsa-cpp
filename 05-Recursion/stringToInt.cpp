#include<iostream>
using namespace std;
int stringToInt(string s,int n)
{
    if(n==0)
    return 0;
    int smaller_ans=stringToInt(s,n-1);
    int ans=smaller_ans*10+(s[n-1]-'0');
    return ans;

}
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    cout<<stringToInt(s,n);
}