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
Node* lca(Node* root, int a, int b)
{
    if(root == nullptr)
    {
        return nullptr ;
    }
    if(root->data == a || root->data == b)
    {
        return root ;
    }
    Node* left =  lca(root->left, a, b)  ;
    Node* right = lca(root->right, a, b) ;
    if(left!= nullptr && right!= nullptr)
    {
        return root ;
    }
    if(left !=nullptr)
    {
        return left ;
    }
    return right ;
    
}
int search(Node*root, int a)
{
    if(root == nullptr)
    {
        return -1;
    }
    if(root->data == a)
    {
        return 0 ;
    }
    int leftLevel= search(root->left, a) ;
    if(leftLevel != -1)
    {
        return leftLevel + 1 ;
    }
    int rightLevel = search(root->right, a) ;
    if(rightLevel != -1)
    {
        return rightLevel + 1 ;
    }
    return -1 ;
}
int main()
{
    Node* root = buildTree() ;
    int a, b ;
    cin >> a >> b ;
    Node* ancestor = lca(root, a, b) ;
    int levelA = search(ancestor, a) ;
    int levelB = search(ancestor, b) ;
    cout << levelA + levelB ;
    
}