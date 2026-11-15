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
    Node* root = new Node(d) ;
    cin >> d ;
    if(d == 0)
    {
        root->left = nullptr ;
        root->right = nullptr ;
    
    }
    else  if(d == 1)
    {
        root->right = nullptr ;
        root->left = buildTree() ;
    
    }
    else if(d == 2)
    {
        root->left = buildTree() ;
        root->right = buildTree() ;
    }
    return root ;
}
void sumKthLevel(Node* root, int k, int& ans)
{
    if(root == nullptr)
    {
        return ;
    }
    if(k == 0)
    {
       ans += root->data ;
        return ;
    }
    sumKthLevel(root->left, k - 1, ans) ;
    sumKthLevel(root->right, k - 1, ans) ; 
}
int main()
{
    Node* root = buildTree() ;
    int k ;
    cin >> k ;
    int ans = 0;
    sumKthLevel(root, k, ans) ; 
    cout << ans ;
}