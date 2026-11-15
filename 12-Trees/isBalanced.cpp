#include<iostream>
#include<algorithm>
using namespace std ;
class Node{
    public:
    string data ;
    Node* left ;
    Node* right ;

    Node(string d) : data(d), left(nullptr), right(nullptr)
    {}
};
Node* buildTree()
{
    string d ; 
    cin >> d ;
    if(d == "false")
    {
        return nullptr ;
    }
    if(d == "true")
    {
        cin >> d ;
    }
    Node* root = new Node(d) ;
    root->left = buildTree() ;
    root->right = buildTree() ;
    return root ;
}
struct Info{
    int height ;
    bool balanced ;
};
Info isBalanced(Node* root)
{
    Info p ;
    if(root == nullptr)
    {
        return {0, true} ;
    }
    Info left = isBalanced(root->left) ;
    Info right = isBalanced(root->right) ;
    p.height = 1 + max(left.height, right.height) ;
    if(abs(left.height - right.height ) <= 1)
    {
        p.balanced = true ;
    } 
    else
    {
        p.balanced = false ;
    }
    return p ;

}
int main()
{
    Node* root = buildTree() ;
    Info ans = isBalanced(root) ;
    cout << boolalpha << ans.balanced ;  
}