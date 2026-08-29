// red
#include <iostream>
using namespace std;
void removeduplicates(char a[])
{
    int prev = 0;
    int l = strlen(a);
    for (int current = 1; current < l; current++)
    {
        if (a[current] != a[prev])
        {
            prev++;
            a[prev] = a[current];
        }
    }
    a[prev + 1] = '\0';
}
int main()
{
    char a[100];
    cin.getline(a, 100);
    removeduplicates(a);
    cout << a;
}