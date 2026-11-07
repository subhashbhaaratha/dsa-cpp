#include<iostream>
using namespace std ;
class Node{
    public :
     int data ;
     Node* left ;
     Node* right ;

    Node(int d) : data(d), left(nullptr), right(nullptr)
    {

    }
};
Node* buildTree()
{
    int d ; 
    cin >> d ;
    if(d == -1)
    {
        return  nullptr ;
    }

    Node* root = new Node(d) ;
    root->left = buildTree() ;
    root->right = buildTree() ;
    return root ;
}
void preorderPrint(Node* root)
{
    if(root == nullptr)
    {
        return ;
    }
    cout << root->data << " " ;
    preorderPrint(root->left) ;
    preorderPrint(root->right) ;
}
void inorderPrint(Node* root)
{
    if(root == nullptr)
    {
        return ;
    }
    inorderPrint(root->left) ;
    cout << root->data << " " ;
    inorderPrint(root->right) ;    
}
void postorderPrint(Node* root)
{
    if(root == nullptr)
    {
        return ;
    }
    postorderPrint(root->left) ;
    postorderPrint(root->right) ;
    cout << root->data << " " ;
}


int main()
{
    Node* root = buildTree() ;
    preorderPrint(root) ;
    cout << endl ;
    inorderPrint(root) ;
    cout << endl ;
    postorderPrint(root) ;
}