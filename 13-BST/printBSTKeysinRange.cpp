#include<iostream>
using namespace std ;
class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;

    Node(int d) : data(d), left(nullptr), right(nullptr)
    {}
};
Node* insertInBST(Node* root, int d)
{
    if(root == nullptr)
    {
        return new Node(d) ;
    }
    if(d < root->data)
    {
        root->left = insertInBST(root->left, d) ;
    }
    else 
    {
        root->right = insertInBST(root->right, d) ;
    }
    return root ;
}
Node* buildTree(int a[], int n)
{
    Node* root = nullptr ;
    for(int i = 0 ; i < n ; i++)
    {
        root = insertInBST(root, a[i]) ;
    }
    return root ;
}
void printPreOrder(Node* root)
{
    if(root == nullptr)
    {
        return ;
    }
    cout << root->data << " " ;
    printPreOrder(root->left) ;
    printPreOrder(root->right) ;
}
void printBSTkeys(Node* root, int k1, int k2)
{
    if(root == nullptr)
    {
        return ;
    }
    printBSTkeys(root->left , k1, k2) ;
    if(k1 <= root->data && root->data <= k2)
    {
        cout << root->data << " " ;
    }
    printBSTkeys(root->right, k1, k2) ;
}
int main()
{
    int t ; 
    cin >> t ;
    while(t--)
    {
        int n ;
        cin >>n ;
        int a[100] ;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a[i] ;
        }
        int k1 , k2 ;
        cin >> k1 >> k2 ;
        Node* root = buildTree(a, n) ;
        cout << "# Preorder : " ;
        printPreOrder(root) ;
        cout <<  endl ;
        cout << "# Nodes within range are : " ;
        printBSTkeys(root, k1, k2) ;
        cout << endl ;
    }
    
}
