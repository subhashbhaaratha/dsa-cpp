#include<iostream>
using namespace std ;
class Node{
    public:
     int data ;
     Node* left ;
     Node* right ;

     Node(int d) : data(d) , left(nullptr), right(nullptr)
     {}
};
Node* buildTree()
{
    int d ; 
    cin >> d ;
    if(d == -1)
    {
        return nullptr ;
    }
    Node* root = new Node(d) ;
    root->left = buildTree() ;
    root->right = buildTree() ;

    return root ;
}
int height(Node* root)
{
    if(root == nullptr)
    {
        return 0 ;
    }
    int h1 = height(root->left) ;
    int h2 = height(root->right) ;
    return 1 + max(h1, h2) ;
}
class Pair{
    public:
     int h ;
     int dm;
     Pair(): h(0) , dm(0) 
     {}
      
};
Pair diameter(Node* root)
{
   if(root == nullptr)
   {
      Pair p0 ;
      p0.h = 0 ;
      p0.dm = 0 ;
      return p0 ;
   }
   Pair p1 = diameter(root->left) ;
   Pair p2 = diameter(root->right) ;  
   Pair p ;
   p.h = max(p1.h , p2.h) + 1 ;
   p.dm = max(p1.h + p2.h , max(p1.dm, p2.dm)) ;
   return p ;
}
int main()
{
    Node* root = buildTree() ;
    Pair p = diameter(root) ;
    cout << p.dm ;
}