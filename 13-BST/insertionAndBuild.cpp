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
Node* insertInBST(Node* root, int d)
{
    if(root == nullptr)
    {
        return new Node(d) ;
    }
    if(d <= root->data)
    {
        root->left = insertInBST(root->left, d) ;
    }
    else
    {
        root->right = insertInBST(root->right, d) ;
    }
    return root ;
}
Node* build()
{
    Node* root = nullptr ;
    int d ;
    cin >> d ;
    while(d != -1)
    {
        root = insertInBST(root, d) ;
        cin >> d ;
    }
    return root ;
}
void inorderPrint(Node* root)
{
    if(root == nullptr)
    return ;
    inorderPrint(root->left) ;
    cout << root->data << "," ;
    inorderPrint(root->right) ;
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
    Node* root = build() ;
    inorderPrint(root) ;
    cout << endl ;
    bfs(root) ;
}