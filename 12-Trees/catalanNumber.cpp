#include<iostream>
#include<queue>
using namespace std ;
class Node{
    public:
     int data ;
     Node* left;
     Node* right ;

     Node(int d) : data(d), left(nullptr), right(nullptr)
     {}
};
int f(int n)
{
    if(n == 0 || n == 1)
    {
        return 1 ;
    }
    int sum = 0 ;
   for(int i = 1 ; i <= n ; i++)
   {
      sum += f(i -1 ) * f(n - i) ;
   }
   return sum ;

}
int fact(int n)
{
    if(n == 0)
    return 1 ;
    return n * fact(n - 1) ;
}
int main()
{
    int n ;
    cin >> n ;
    cout << "No of BST's : " <<  f(n) << endl ;
     cout << "No of unlabbeled trees : " << f(n) << endl;
    cout << "No of Binary Trees : " << fact(n) * f(n) << endl ;
   
}