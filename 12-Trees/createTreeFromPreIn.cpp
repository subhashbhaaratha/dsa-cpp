#include<iostream>
#include<queue>
using namespace std ;
class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;

    Node(int d): data(d), left(nullptr), right(nullptr)
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
void bfs(Node* root)
{
    if(root == nullptr)
    return ;
    queue<Node*>q ;
    q.push(root) ;
    while(!q.empty())
    {
        int levelsize = q.size() ;
        while(levelsize--)
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
    }
}
int main()
{
    int n ; 
    cin >> n ;
    int pre[100001] ;
    int in[100001] ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> pre[i] ;
    }
    for(int i = 0 ; i < n ; i++)
    {
        cin >> in[i] ;
    }
    int i = 0 ;
    Node* root = buildTree(pre, in, 0, n - 1 , i) ;
    bfs(root) ;
}