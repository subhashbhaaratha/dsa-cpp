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
int main()
{
    Node* root = buildTree() ;
    int a, b ;
    cin >> a >> b ;
    Node* ans = lca(root, a, b) ;
    cout << ans->data ;
}