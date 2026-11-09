#include<iostream>
using namespace std ;
class Node{
    public:
     int data ;
     Node* left ;
     Node* right ;

     Node(int d) : data(d) , left(nullptr), right(nullptr)
     {}
};
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
void printKthLevel(Node* root, int k)
{
    if(root == nullptr)
    {
        return ;
    }
    if(k == 0)
    {
        cout << root->data << " " ;
        return ;
    }
    printKthLevel(root->left, k - 1) ;
    printKthLevel(root->right, k - 1) ;

}
int NodesAtDistK(Node* root, int target, int k)
{
    if(root == nullptr)
    {
        return -1 ;
    }
    if(root->data == target)
    {
        printKthLevel(root, k) ;
        return 0 ;
    }
    
   
    int rightD = NodesAtDistK(root->right, target, k) ; 
    
    if( rightD != -1)
    {
        
         if(rightD + 1 == k)
        {
            cout << root->data << " " ;
           
        }
        else if(rightD + 1 < k )
        {
            printKthLevel(root->left, k - 2 - rightD) ;
        }
       return rightD + 1 ;
    }
    int leftD =  NodesAtDistK(root->left, target, k) ;
    if( leftD != -1)
    {
        
        if(leftD + 1 == k)
        {
            cout << root->data << " " ;
          
        }
        else if(leftD + 1 < k)
        {
            printKthLevel(root->right, k - 2 - leftD) ;
        }
        return leftD + 1 ;
    } 
   return -1 ; 
}
int main()
{
    Node* root = buildTree() ;
    int target , k ;
    cin >> target >> k ;
    NodesAtDistK(root, target, k) ;


}