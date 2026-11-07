#include<iostream>
#include<queue>
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
int countNodes(Node* root)
{
    if(root == nullptr)
    {
        return 0 ;
    }
    int c1 = countNodes(root->left) ;
    int c2 = countNodes(root->right) ;
    return 1 + c1 + c2 ;
}
int sumOfAllNodes(Node* root)
{
    if(root == nullptr)
    {
        return 0 ;
    }
    int s1 = sumOfAllNodes(root->left) ;
    int s2 = sumOfAllNodes(root->right) ;
    return root->data + s1 + s2 ;
}

int main()
{
    Node* root = buildTree() ;
    cout << countNodes(root) << endl << sumOfAllNodes(root) ;
}