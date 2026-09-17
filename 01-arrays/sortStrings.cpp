#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
bool compare(string s1,string s2){
    if(s1.size()>s2.size()&& s1.compare(0,s2.size(),s2)==0)
{
    return true;
}
 if(s2.size()>s1.size()&& s2.compare(0,s1.size(),s1)==0)
{
    return true;
}
return s1<s2;
}
int main(){
    int n;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++)
    cin>>s[i];
    sort(s.begin(),s.end(),compare);
    for(int i=0;i<n;i++)
    cout<<s[i]<<endl;


}