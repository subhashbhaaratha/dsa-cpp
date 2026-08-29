#include <iostream>
using namespace std;
int main()
{
    // char a[][10]={{'a','b','c','\0'},{'d','e','f','\0'}};
    // cout<<a[0]<<endl;
    // cout<<a[1]<<endl;
    char a[100][1000];
    int n;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        cin.getline(a[i], 1000);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}