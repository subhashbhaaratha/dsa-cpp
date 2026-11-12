#include<iostream>
using namespace std ;
class Node{
    public:
     int data ;
     Node* left;
     Node* right ;

     Node(int d) : data(d), left(nullptr), right(nullptr)
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
    int d ;
    cin >> d ;
    Node* root = nullptr ;
    while(d != -1)
    {
        root = insertInBST(root, d) ;
        cin >> d ;
    }

    return root ;
}
struct LinkedList{
        Node* head ;
        Node* tail ;
};
LinkedList bstToLL(Node* root)
{
    if(root == nullptr)
    {
        return {} ;
    }
   LinkedList leftLL = bstToLL(root->left) ;
   LinkedList rightLL = bstToLL(root->right) ;
   Node* head ;
   Node* tail ;
   if(leftLL.tail != nullptr)
   {
    leftLL.tail->right = root ;
    head = leftLL.head ;
   }
   else
   {
        head = root ;
   }
   if(rightLL.head !=nullptr)
   {
       root->right = rightLL.head ;
       tail = rightLL.tail ;
   }
   else
   {
    tail = root ;
   }
   root->left = nullptr ;
   return {head,tail} ;
   
}

int main()
{
    Node* root = build() ;
    LinkedList ans =  bstToLL(root) ;
    Node* temp = ans.head ;
    while(temp!= nullptr)
    {
        cout << temp->data << "->" ;
        temp = temp->right ;
    }
}