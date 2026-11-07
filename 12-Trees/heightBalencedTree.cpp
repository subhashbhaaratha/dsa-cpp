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
struct Pair{
    int height ;
    bool balenced ;

};
Pair balencedTree(Node* root)
{
    Pair p ;
    if(root == nullptr)
    {
        
        p.height = 0 ;
        p.balenced = true ;
        return p ;
    }
    Pair left = balencedTree(root->left) ;
    Pair right = balencedTree(root->right) ;
    p.height = max(left.height, right.height) + 1 ;
    int diff ;
    diff = left.height > right.height ? left.height - right.height : right.height - left.height ;
    if(left.balenced == false || right.balenced == false)
    {
        p.balenced = false ;
    }
    else
    {
         p.balenced = diff <= 1 ? true : false ;
    }
   
    return p ;
}
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
int main()
{
    Node* root = buildTree() ;
    Pair p = balencedTree(root) ;
    cout << p.balenced ;
}