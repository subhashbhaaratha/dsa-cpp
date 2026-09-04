#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int converttonumber(string s)
{
    int p = 1;
    int number = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        number += (s[i] - '0') * p;
        p = p * 10;
    }
    return number;
}

bool numeric_compare(pair<string, string> p1, pair<string, string> p2)
{
    string key1, key2;
    key1 = p1.second;
    key2 = p2.second;
    return converttonumber(key1) < converttonumber(key2);
}
bool lexico_compare(pair<string, string> p1, pair<string, string> p2)
{
    string key1, key2;
    key1 = p1.second;
    key2 = p2.second;
    return key1 < key2;
}

string getatoken(string str, int key)
{
    char *s = strtok((char *)str.c_str(), " ");

    while (key > 1)
    {
        s = strtok(nullptr, " ");
        key--;
    }

    return (string)s;
}

using namespace std;
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string s[100];
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    int key;
    cin >> key;

    bool rev;
    cin >> boolalpha >> rev;

    string type;
    cin >> type;
    // //    cin.ignore();
    // //    string type1;
    // //    getline(cin,type1);
    // //    char type2[100];
    // //    cin>>type2;
    // //    cin.ignore();
    // //    char type3[100];
    // //    cin.getline(type3,100);
    pair<string, string> sp[100];
    for (int i = 0; i < n; i++)
    {
        sp[i].first = s[i];
        sp[i].second = getatoken(s[i], key);
    }
    if (type == "numeric")
        sort(sp, sp + n, numeric_compare);
    else if (type == "lexicographic")
        sort(sp, sp + n, lexico_compare);

    if (rev == true)
    {
        for (int i = 0; i < n / 2; i++)
        {
            swap(sp[i], sp[n - i - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << sp[i].first << endl;
    }
}