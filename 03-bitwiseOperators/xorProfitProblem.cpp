#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int x, y, value;
    cin >> x >> y;
    int p = x ^ y;
    int count=0;
    while(p>0){
       p=p>>1;
        count++;
    }
    cout<<((1<<(count))-1);

}
