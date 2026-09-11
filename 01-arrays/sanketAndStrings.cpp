#include <iostream>
#include <algorithm>
using namespace std;
int longestWindow(string s, int k, char b)
{
    int left = 0, right = 0, b_count = 0, max_count = 0, len = s.length();
    while (left <= right && right < len)
    {
        if (s[right] == b)
            b_count++;
        while (b_count > k)
        {
            if (s[left] == b)
                b_count--;
            left++;
        }
        max_count = max(max_count, right - left + 1);
        right++;
    }
    return max_count;
}
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int makeA = longestWindow(s, k, 'b');
    int makeB = longestWindow(s, k, 'a');
    cout << max(makeA, makeB);
}