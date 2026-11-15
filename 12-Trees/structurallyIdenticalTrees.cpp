#include<iostream>
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
    return nullptr ;
    if(d == "true")
    {
        cin >> d;
    }
    Node* root = new Node(d) ;
    root->left = buildTree() ;
    root->right = buildTree() ;
    return root ;
}
bool compare_Trees(Node* root1, Node* root2)
{
    if(root1 == nullptr && root2 == nullptr)
    return true ;
    if(root1 == nullptr && root2 != nullptr)
    {
        return false ;
    }
    if(root1 != nullptr && root2 == nullptr)
    {
        return false ;
    }
    bool left = compare_Trees(root1->left, root2->left) ;
    if(!left)
    return false ;
    bool right = compare_Trees(root1->right, root2->right) ;
    if(!right)
    return false ;
    return true ;

}
int main()
{
    Node* root1 = buildTree() ;
    Node* root2 = buildTree() ;
    bool ans = compare_Trees(root1, root2) ;
    if(ans == 1)
    {
        cout << "true" ;
    }
    else
    {
        cout << "false" ;
    }

    


}