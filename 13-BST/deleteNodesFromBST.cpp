#include<iostream>
#include<vector>
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
       root->left =  insertInBST(root->left, d) ;
    }
    else
    {
       root->right = insertInBST(root->right, d) ; 
    }
    return root ;
}
Node* build(int a[], int n)
{
    Node* root = nullptr ;
    for(int i = 0 ; i < n ; i++)
    {
        root = insertInBST(root, a[i]) ;
    }
    return root ;
}
Node* deleteNode(Node* root, int d)
{
    if(root == nullptr)
    {
        return nullptr ;
    }
    if(root->data > d)
    {
        root->left = deleteNode(root->left, d) ;
        
    }
    else if( root->data < d)
    {
        root->right = deleteNode(root->right, d) ;
    
    }
    else if (root->data == d)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root ;
            return nullptr ;
        }
        else if(root->left != nullptr && root->right == nullptr)
        {
            Node* temp = root->left ;
            delete root ;
            return temp ;
        }
        else if(root->right != nullptr && root->left == nullptr)
        {
            Node* temp = root->right ;
            delete root ;
            return temp ;
        }
        else
        {
            Node* temp = root->right ;
            while(temp->left != nullptr)
            {
                temp = temp->left ;
            }
            root->data = temp->data ;
            root->right = deleteNode(root->right, temp->data) ;
        }

    }
    
    return root ;
}
void printPreOrder(Node* root)
{
    if(root == nullptr)
    {
        return ;
    }
    cout << root->data << " ";
    printPreOrder(root->left) ;
    printPreOrder(root->right) ;

}
int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
    int n ; 
    cin >> n ;
    int a[1001] ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i] ;
    }
    Node* root = build(a, n) ;
    int m ;
    cin >> m ;
    int b[1001] ;
    for(int i =0 ; i < m ; i++)
    {
        cin >> b[i] ;
    }
    for(int i= 0 ; i < m ; i++)
    {
        root = deleteNode(root, b[i]) ;
    }
    printPreOrder(root) ;
    
}

}