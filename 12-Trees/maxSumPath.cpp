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
class Pair 
{
    public:
    int maxbranchSum ;
    int maxpathSum ;
   
};
Pair maxSumPath(Node* root)
{
    Pair p ;
    if(root == nullptr)
    {
        return {0, INT_MIN} ;
    }
    Pair left = maxSumPath(root->left) ;
    Pair right = maxSumPath(root->right) ;
    int sum1 = root->data ;
    int sum2 = root->data + right.maxbranchSum ;
    int sum3 = root->data + left.maxbranchSum ;
    int sum4 = root->data + left.maxbranchSum + right.maxbranchSum ;
    int bigSum = max(max(sum1, sum2), max(sum3, sum4)) ;
    
    p.maxpathSum = max(bigSum, max(left.maxpathSum, right.maxpathSum)) ;
    p.maxbranchSum = max(sum1, max(sum2, sum3)) ;
    return p ;
}
int main()
{
    Node* root = buildTree() ;
    Pair p = maxSumPath(root) ;
    cout << p.maxpathSum ;


}