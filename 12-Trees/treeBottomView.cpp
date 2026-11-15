#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std ;
class Node{
    public:
    int data ;
    int dist ;
    Node* left ;
    Node* right ;

    Node(int d, int distance) : data(d), dist(distance), left(nullptr), right(nullptr)
    {}
};

Node* buildTree()
{
    queue<Node*> q ;
    int d ;
    cin >> d ;
    Node* root = new Node(d,0) ;
    q.push(root) ;
    while(!q.empty())
    {
        
        Node* f = q.front() ; 
        q.pop() ;
        cin >> d ;
        if(d != -1)
        {
            f->left = new Node(d,f->dist - 1) ;
            q.push(f->left) ;
        }
        else
        {
            f->left = nullptr ;
        }
        cin >> d ;
        if(d != -1)
        {
            f->right = new Node(d,f->dist + 1) ;
            q.push(f->right) ;
        }
        else
        {
            f->right = nullptr ;
        }
    }
    return root ;
}
bool compare(Node* v1 , Node* v2)
{
    return v1->dist < v2->dist ;
}
void replace(vector<Node*>&ans, Node* f)
{
    for(int i = 0 ; i < ans.size() ; i++)
    {
        if(f->dist == ans[i]->dist)
        {
            ans[i] = f ;
            return ;
        }
    }
    ans.push_back(f) ;
}
void bottomView(Node* root)
{
   queue<Node*>q ;
   vector<Node*>ans ;
   q.push(root) ;
  
   while(!q.empty())
   {
        Node* f = q.front() ;
        q.pop() ; 
        replace(ans,f) ;
        if(f->left != nullptr)
        {
            q.push(f->left) ;
        }
        if(f->right != nullptr)
        {
            q.push(f->right) ;
        }
   }
   sort(ans.begin(), ans.end(),compare) ;
   for(auto s : ans)
   {
    cout << s->data << " " ;
   }
}
int main()
{
    Node* root = buildTree() ;
    bottomView(root) ;
   
}