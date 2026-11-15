#include<iostream>
#include<queue>
using namespace std ;
class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;

    Node(int d) : data(d), left(nullptr), right(nullptr)
    {}
};
Node* buildTree()
{
    queue<Node*> q ;
    int d ;
    cin >> d ;
    Node* root = new Node(d) ;
    q.push(root) ;
    while(!q.empty())
    {
        Node* f = q.front() ;
        q.pop() ;
        cin >> d ;
        if(d != -1)
        {
            f->left = new Node(d) ;
            q.push(f->left) ;
        }
        else
        {
            f->left = nullptr ;
        }
        cin >> d ;
        if(d != -1)
        {
            f->right = new Node(d) ;
            q.push(f->right) ;
        }
        else
        {
            f->right = nullptr ;
        }
    }
    return root ;

}
void leftView(Node* root, int level , int& maxLevel)
{
    if(root == nullptr)
    {
        return ;
    }
    if(level > maxLevel)
    {
        cout << root->data << " " ;
        maxLevel = level ;
    }
    leftView(root->left, level + 1, maxLevel) ;
    leftView(root->right, level + 1, maxLevel) ;
}
int main()
{
    Node* root = buildTree() ;
    int maxLevel = 0 ;
    leftView(root, 1, maxLevel) ;
}