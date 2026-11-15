#include<iostream>
#include<vector>
#include<queue>
using namespace std ;
class Node{
    public:
     string data ;
     Node* left ;
     Node* right ;

     Node(string d) : data(d) , left(nullptr), right(nullptr)
     {}
};
Node* buildTree()
{
    string d ;
    cin >> d ;
    if(d == "false")
    {
        return nullptr ;
    }
    if( d == "true")
    {
        cin >> d ;
    }
    Node* root = new Node(d) ;
    root->left = buildTree();
    root->right = buildTree() ;
    return root ;
    
}
void zigZag(Node* root)
{
    queue<Node*> q ;
    q.push(root) ;
    int level = 0 ;
    while(!q.empty())
    {
        level++ ;
        int k = q.size() ;
        vector<Node*>v;
        while(k--)
        {
            Node* f = q.front() ;
            q.pop() ;
            v.push_back(f) ;
            if(f->left != nullptr)
            {
                q.push(f->left) ;
            }
            if(f->right != nullptr)
            {
                q.push(f->right) ;
            }
        }
        if((level&1)== 1)
        {
            for(int i = 0 ; i < v.size() ; i++)
            {
                cout << v[i]->data << " " ;
            }
        }
        else
        {
            for(int i = v.size() - 1 ; i>=0 ; i--)
            {
                cout << v[i]->data << " " ;
            }
        }
        v.clear() ;
    }
}
int main()
{
    Node* root = buildTree() ;
    zigZag(root) ;

}
