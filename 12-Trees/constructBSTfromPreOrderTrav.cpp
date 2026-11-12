#include<iostream>
#include<queue>
using namespace std ;
class Node{
    public:
     int data ;
     Node* left;
     Node* right ;

     Node(int d) : data(d), left(nullptr), right(nullptr)
     {}
};
int search(int in[], int s, int e, int target)
{
    for(int i = s ; i <= e ; i++)
    {
        if(in[i] == target)
        {
            return i ;
        }
    }
    return -1;
}
Node* constructBST(int pre[], int in[], int s, int e, int& i)
{
    if(s > e)
    {
        return nullptr ;
    }
    int idx =  search(in, s, e, pre[i]) ;
    Node* root = new Node(pre[i]) ;
    i++ ;
    root->left = constructBST(pre, in, s, idx - 1, i) ;
    root->right = constructBST(pre, in, idx + 1, e, i) ;
    return root ;
 }
 Node* constructBST2(int pre[], int n, int& i, int low, int high)
 {
    if( i == n)
    {
        return nullptr;
    }
    int value = pre[i] ;
    if(value <= low || value >= high)
    {
        return nullptr ;
    }
    Node* root = new Node(value) ;
    i++ ;
    root->left = constructBST2(pre, n, i, low, value) ;
    root->right = constructBST2(pre, n, i, value, high) ;
    return root ;
 }
 void bfs(Node* root)
{
    queue<Node*> q ;
    q.push(root) ;
    while(!q.empty())
    {
        int levelSize = q.size() ;
        while(levelSize--)
        {
            Node* f = q.front() ;
            q.pop() ;
            cout << f->data << " " ;
            if(f->left != nullptr)
            {
                q.push(f->left) ;
            }
            if(f->right != nullptr)
            {
                q.push(f->right) ;
            }
        }
        cout << '\n' ;
    }
}

int main()
{
    // int n ;
    // cin >> n ;
    // int pre[100], in[100] ;
    // for(int i = 0 ; i < n ; i++)
    // {
    //     cin >> pre[i] ;
    //     in[i] = pre[i] ;
    // }
    // sort(in, in + n) ;
    // int i = 0 ;
    // Node* root = constructBST(pre, in, 0 , n - 1, i) ;
    // bfs(root) ;
    int n ;
    cin >> n ;
    int pre[100];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> pre[i] ;

    }

    int i = 0 ;
    Node* root = constructBST2(pre, n, i, INT_MIN, INT_MAX) ;
    bfs(root) ;



}