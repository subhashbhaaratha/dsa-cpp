#include<iostream>
#include<ctime>
using namespace std;
void bubble_sort(int *a,int n)
{
    for(int itr=1;itr<=n-1;itr++){
        for(int j=0;j<=n-itr-1;j++){
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
    }
}
int main()
{
   int n;
   cin>>n;
   int a[1000000];
   int b[1000000];
   for(int i=0;i<n;i++)
   {
    a[i] = n-i;
    b[i] = n-i;
   }
   clock_t start = clock() ;
   bubble_sort(a,n) ;
   clock_t end = clock();
   cout << "BubbleSort " << end-start << endl ;
   start = clock();

   sort(b , b + n) ;
   end = clock() ;
   cout << "std::sort " << end-start << endl ; 
}