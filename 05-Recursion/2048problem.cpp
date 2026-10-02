#include<iostream>
using namespace std;
void spelling(int n)
{
    if(n==0)
    return;
    spelling(n/10);
    string words[]={"zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"};
    cout<<words[n%10];


}
int main()
{
    int n;
    cin>>n;
    spelling(n);
}