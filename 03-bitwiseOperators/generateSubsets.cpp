#include <iostream>
#include <vector>
using namespace std;
void filter(int a, string s)
{
    if (a == 0)
    {
        cout << " ";
    }
    int i = 0;
    while (a > 0)
    {
        if ((a & 1) == 1)
            cout << s[i];
        i++;
        a = a >> 1;
    }
    cout << endl;
}
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    int n = (1 << len);
    for (int i = 0; i < n; i++)
    {
        filter(i, s);
    }
}