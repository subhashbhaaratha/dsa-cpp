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
    cout << root->data << ",";
    inorderPrint(root->right) ;
}
Node* deleteInBST(Node* root, int d)
{
    if(root == nullptr)
    {
        return nullptr ;
    }
    if(d < root->data)
    {
        root->left = deleteInBST(root->left, d) ;
    }
    else if(d == root->data)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root ;
            return nullptr ;
        }
        if(root->left != nullptr && root->right == nullptr)
        {
            Node* temp = root->left ;
            delete root ;
            return temp ;
        }
        if(root->right != nullptr && root->left == nullptr)
        {
            Node* temp = root->right ;
            delete root ;
            return temp ;
        }
        if(root->left != nullptr && root->right != nullptr)
        {
            Node* replace = root->right ;
            while(replace->left != nullptr)
            {
                replace = replace->left ;
            }
            root->data = replace->data ;
            root->right = deleteInBST(root->right, replace->data) ;
            //  Node* replace = root->left ;
            // while(replace->right != nullptr)
            // {
            //     replace = replace->right ;
            // }
            // root->data = replace->data ;
            // root->left = deleteInBST(root->left, replace->data) ;

        }
    }
    else if(d > root->data)
    {
        root->right = deleteInBST(root->right, d) ;
    }
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
    Node* root = build() ;
    int d ;
    cin >> d ;
    inorderPrint(root) ;
    cout << endl ;
    root = deleteInBST(root, d) ;
    inorderPrint(root) ;
    cout << endl ;
    bfs(root) ;
}