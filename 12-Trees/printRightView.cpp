#include<iostream>
#include<queue>
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
void printRightView(Node* root, int level, int& maxLevel)
{
    if(root == nullptr)
    {
        return ;
    }
    if(level > maxLevel)
    {
        cout << root->data << " ";
        maxLevel = level ;
    }

    printRightView(root->right, level + 1, maxLevel) ;
    printRightView(root->left, level + 1, maxLevel) ;
}
int main()
{
    Node* root = buildTree() ;
    int maxLevel = -1 ;
    printRightView(root, 0, maxLevel) ;
}