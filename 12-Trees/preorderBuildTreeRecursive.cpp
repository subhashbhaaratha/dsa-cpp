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
        return nullptr ;
    }
    Node* root = new Node(d) ;
    root->left = buildTree() ;
    root->right = buildTree() ;
    return root ;
}
void print(Node* root)
{
    if(root == nullptr)
    {
        return ;
    }
    cout << root->data << " " ;
    print(root->left) ;
    print(root->right) ;
}
int main()
{
   Node* root = buildTree() ;
   print(root) ;
}