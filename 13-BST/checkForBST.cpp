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
Node* buildTree()
{
   
    int d ;
    cin >> d ;
    if(d == -1)
    {
        return nullptr ;
    }
    Node* root = new Node(d) ;
    root->left = buildTree() ;
    root->right = buildTree() ;
    return root ;
}
bool checkForBST(Node* root, int min, int max)
{
    if(root == nullptr)
    {
        return true ;
    }
    if(!(min <= root->data) || !(root->data <= max) )
    {
        return false ;
    }
    bool left = checkForBST(root->left, min, root->data) ;
    if(!left)
    {
        return false ;
    }
    bool right = checkForBST(root->right, root->data, max) ;
    if(!right)
    {
        return false ;
    }
    return true ;

}
struct Info{
    int min ;
    int max ;
    bool result ;
};
Info isBST(Node* root)
{
    Info p ;
    if(root == nullptr)
    {
        return{INT_MAX, INT_MIN, true} ;
    }
    Info left = isBST(root->left) ;
    Info right = isBST(root->right) ;
    if(root->data > left.max && root->data < right.min && left.result && right.result)
    {
        p.result = true ;
    }
    else
    {
        p.result = false ;
    }
    p.min = min(root->data , min(left.min, right.min)) ;
    p.max = max(root->data, max(left.max, right.max)) ;
    return p ;
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
    // Node* root = buildTree() ;
    // bfs(root) ;
    // cout << endl ;
    // cout << boolalpha << checkForBST(root, INT_MIN, INT_MAX) ;
    // Node* root = build() ;
    // bfs(root) ;
    // cout << endl ;
    // Info ans = isBST(root) ;
    // cout << boolalpha << ans.result ;
    Node* root = buildTree() ;
    bfs(root) ;
    cout << endl ;
    Info ans =  isBST(root) ;
    cout << boolalpha << ans.result ;


    
}