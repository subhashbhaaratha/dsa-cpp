#include<iostream>
using namespace std ;
int main()
{
    char a[] = "abdcdxyzc" ;
    int n = strlen(a) ;
    int freq[26] = {0} ;
    char ch = a[0] ;
    freq[ch - 'a']++ ;
    int maxCount = 1 ;
     int left = 0 , right = 1 ;
    while(right < n )
    {
        char ch = a[right] ;
        freq[ch - 'a']++ ;
        while(freq[ch - 'a'] > 1)
        {
            
            freq[a[left] - 'a']-- ;
            left++ ;
        }
        maxCount =max(maxCount, right - left + 1) ;
        right++ ;
    }
    cout << maxCount ;
}
