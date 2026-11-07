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
Node* buildbalencedTree(int a[], int s, int e)
{
    if(s > e)
    {
        return nullptr ;
    }
    int mid = ( s + e ) / 2 ;
    Node* root = new Node(a[mid]) ;
    root->left = buildbalencedTree(a, s, mid - 1) ;
    root->right = buildbalencedTree(a, mid + 1, e) ;
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
    int n ; 
    cin >> n ;
    int a[100] ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i] ;
    }
    Node* root = buildbalencedTree(a, 0, n - 1) ;
    bfs(root) ;

}