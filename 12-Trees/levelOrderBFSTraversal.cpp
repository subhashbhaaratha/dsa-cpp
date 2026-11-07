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
void bfsTraversal(Node* root)
{
    queue<Node*>q ;
    q.push(root) ;
    while(!q.empty())
    {
        Node* temp = q.front() ;
        cout << temp->data << " " ;
        
        q.pop() ;
        if(temp->left != nullptr)
        {
            q.push(temp->left) ;
        }
         if(temp->right != nullptr)
        {
            q.push(temp->right) ;
        }  
          
    }
}
int main()
{
    Node* root = buildTree() ;
    bfsTraversal(root) ;
}