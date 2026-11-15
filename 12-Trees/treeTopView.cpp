#include<iostream>
#include<vector>
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
bool isPresent(vector<int> used, int dist)
{
    for(int i = 0 ; i < used.size() ; i++)
    {
        if(used[i] == dist)
        {
            return true ;
        }
    }
    return false ;
}
bool compare(Node* v1 , Node* v2)
{
    return v1->dist < v2->dist ;
}
void topView(Node* root)
{
   queue<Node*>q ;
   vector<int>used ;
   vector<Node*>ans ;
   q.push(root) ;
  
   while(!q.empty())
   {
        Node* f = q.front() ;
        q.pop() ;
        if(!isPresent(used,f->dist))
        {
            ans.push_back(f) ;
            used.push_back(f->dist) ;
        }
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
    topView(root) ;
   
}