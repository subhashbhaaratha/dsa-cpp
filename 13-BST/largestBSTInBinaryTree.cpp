#include<iostream>
#include<climits>
using namespace std ;
class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;

    Node(int d) : data(d), left(nullptr), right(nullptr)
    {}
};
int search(int in[], int s, int e, int value)
{
    for(int i = s ; i <= e ; i++)
    {
        if(in[i] == value)
        {
            return i ;
        }
    }
    return -1 ;
}
Node* buildTree(int pre[], int in[], int s, int e, int& i)
{
    if(s > e)
    {
        return nullptr ;
    }
    int value = pre[i] ;
    i++ ;
    int idx = search(in, s, e, value) ;
    Node* root = new Node(value) ;
    root->left = buildTree(pre, in, s, idx - 1, i) ;
    root->right = buildTree(pre, in, idx + 1, e, i) ;
    return root ;
}
struct Info{
    int min ;
    int max ;
    bool isBST ;
    int number ;
};
Info largestBST(Node* root, int& ans)
{
    Info p ;
    if(root == nullptr)
    {
        return {INT_MAX, INT_MIN, true, 0} ;
    }
    Info left = largestBST(root->left, ans) ;
    Info right = largestBST(root->right, ans) ;
    p.min = min(root->data, min(left.min, right.min)) ;
    p.max = max(root->data, max(left.max, right.max)) ;
    p.isBST = (root->data > left.max) && (root->data < right.min) && (left.isBST ) && (right.isBST ) ;
    p.number = 1 + left.number + right.number ;
    if(p.isBST && p.number > ans)
    {
        
        ans = p.number ;
    }
    return p ;
}

int main()
{
    int n ;
    cin >> n ;
    int pre[1001] ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> pre[i] ;
    }
    int in[1001] ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> in[i] ;
    }
    int i = 0 ;
    Node* root = buildTree(pre, in, 0, n - 1, i) ;
    int ans = 0 ;
    largestBST(root, ans) ;
    cout << ans ;


}