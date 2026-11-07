#include<iostream>
#include<queue>
using namespace std ;
class Node{
    public:
     int data ;
     Node* left ;
     Node* right ;

     Node(int d) : data(d) , left(nullptr), right(nullptr)
     {}
};
int searchvalue(int in[], int value, int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(in[i] == value)
        {
            return i ;
        }
    }
    return -1;
}
Node* buildTree(int pre[], int& k, int in[], int s, int e, int n)
{
    if(s > e)
    {
       
        return nullptr ;
    }
    int value = pre[k] ;
    Node* root = new Node(value) ;
    k++;
    int i = searchvalue(in, value, n) ;
    root->left = buildTree(pre, k , in, s, i - 1, n) ;
    root->right = buildTree(pre, k , in, i + 1, e, n) ;
    return root ;

}
void bfs(Node* root)
{
    queue<Node*> q ;
    q.push(root) ;
    q.push(nullptr) ;
    while(!q.empty())
    {
        Node* f = q.front() ;
        cout << f->data << " " ;
        q.pop() ;
        if(f->left)
        {
            q.push(f->left) ;
        }
        if(f->right)
        {
            q.push(f->right) ;
        }
        if(q.front() == nullptr)
        {
            q.pop() ;
            if(q.empty())
            break ;
            cout << endl ;
            q.push(nullptr) ;
        }
    }
}
int main()
{
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7} ;
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5} ;
    int n = 8 ;
    int k = 0 ;
    Node* root = buildTree(pre, k, in, 0, n - 1, n) ;
    bfs(root) ;

 }