#include<iostream>
#include<queue>
using namespace std ;
class Node{
    public :
     int data ;
     Node* left ;
     Node* right ;

    Node(int d) : data(d), left(nullptr), right(nullptr)
    {

    }
};
Node* buildTree()
{
    int d ; 
    cin >> d ;
    if(d == -1)
    {
        return  nullptr ;
    }

    Node* root = new Node(d) ;
    root->left = buildTree() ;
    root->right = buildTree() ;
    return root ;
}
void bfs1(Node* root)
{
   queue<pair<Node*, int>>q ;
   q.push({root,1}) ;
   int l = 1 ;
   while(!q.empty())
   {
      Node* f = (q.front()).first ;
     
      if(((q.front()).second) > l)
      {
        cout << endl ;
      }
       cout << f->data << " ";
      l = (q.front()).second ;
      q.pop() ;
      if(f->left)
      {
        q.push({f->left, l + 1}) ;
      }
      if(f->right)
      {
        q.push({f->right, l + 1}) ;
      }
    }
}
void bfs2(Node* root)
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
    Node* root = buildTree() ;
    bfs2(root) ;
}