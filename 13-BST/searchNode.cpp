#include<iostream>
#include<queue>
using namespace std ;
class Node{
    public:
       int data ;
       Node* left ;
       Node* right ;
    Node(int d): data(d), left(nullptr), right(nullptr)
    {}
};
Node* insertInBST(Node* root, int d)
{
    if(root == nullptr)
    {
        return new Node(d) ;
    }
    if(d <= root->data)
    {
        root->left = insertInBST(root->left, d) ;
    }
    else
    {
        root->right = insertInBST(root->right, d) ;
    }
    return root ;
}
Node* build()
{
    Node* root = nullptr ;
    int d ;
    cin >> d ;
    while(d != -1)
    {
        root = insertInBST(root, d) ;
        cin >> d ;
    }
    return root ;
}
bool search(Node* root, int target)
{
    if(root == nullptr)
    {
        return false ;
    }
    if(target == root->data)
    {
        return true ;
    }
    else if(target < root->data)
    {
        return search(root->left, target) ;
    }
    else
    {
        return search(root->right, target) ;
    }
}
int main()
{
    Node* root = build() ;
    int target ;
    cin >> target ;
    cout << search(root, target) ;
}