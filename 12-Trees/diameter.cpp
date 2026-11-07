#include<iostream>
using namespace std ;
class Node{
    public: 
      int data ;
      Node* left ;
      Node* right ;

    Node(int d) : data(d), left(nullptr), right(nullptr)
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
int diameter(Node* root)
{
    if(root == nullptr)
    {
        return 0 ;
    }
    int d1 = height(root->left) + height(root->right) ;
    int smax = max(diameter(root->left), diameter(root->right)) ;
    return max(smax, d1) ;
}

int main()
{
    Node* root = buildTree() ;
   cout << diameter(root) ;
}