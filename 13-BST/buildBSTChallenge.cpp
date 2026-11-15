#include<iostream>
using namespace std ;
class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;

    Node(int d):data(d),left(nullptr), right(nullptr)
    {}
};
Node* buildTree(int a[], int s, int e)
{
    if(s > e)
    {
        return nullptr ;
    }
    int mid = (s+ e)/2 ;
    Node* root = new Node(a[mid]) ;
    root->left = buildTree(a, s, mid-1) ;
    root->right = buildTree(a,mid+1, e) ;
    return root ;
}
void printPreOrder(Node* root)
{
    if(root == nullptr)
    return ;
    cout << root->data << " " ;
    printPreOrder(root->left) ;
    printPreOrder(root->right) ;
}
int main()
{
    int t;
    cin >> t ;
    while(t--)
    {
        int n ;
        cin >> n ;
        int a[1001] ;
        for(int i = 0 ; i < n ; i++)
        cin >>a[i] ;
        Node* root = buildTree(a, 0, n-1) ; 
        printPreOrder(root) ;
    }
}