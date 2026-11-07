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
int height(Node* root)
{
    if(root == nullptr)
    {
        return 0 ;
    }
    int h1 = height(root->left) ;
    int h2 = height(root->right) ;
    int ans = max(h1, h2) + 1 ;
    return ans ;
}
void printKthLevel(Node* root , int k)
{
    if(root == nullptr)
    {
        return ;
    }
    if(k == 1)
    {
        cout << root->data << " " ;
        return ;
    }
    printKthLevel(root->left, k - 1) ;
    printKthLevel(root->right, k - 1) ;


}
void printAllLevels(Node* root)
{
    int h = height(root) ;
    for(int k = 1 ; k <= h ; k++)
    {
        printKthLevel(root, k) ;
        cout << endl ;
    }
}

int main()
{
    Node* root = buildTree() ;
    printAllLevels(root) ;
}