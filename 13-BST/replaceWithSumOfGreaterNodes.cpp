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
Node* build(int a[], int s, int e)
{
    if(s > e)
    {
        return nullptr ;
    }
    int mid = (s + e) / 2 ;
    Node* root = new Node(a[mid]) ;
    root->left = build(a, s, mid - 1) ;
    root->right = build(a, mid + 1, e) ;
    return root ;
}
void replace(Node* root, int& value)
{
    if(root == nullptr)
    {
        return ;
    }
    replace(root->right, value) ;
    root->data = root->data + value ;
    value = root->data ;
    replace(root->left, value) ;  
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
    int n ; 
    cin >> n ; 
    int a[1001] ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i] ;
    }
    Node* root = build(a, 0, n - 1) ;
    int value ;
    replace(root, value) ;
    printPreOrder(root) ;

}