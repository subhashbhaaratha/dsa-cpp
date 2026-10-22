#include<iostream>
using namespace std; 
class Node{
    public:
      int data ;
      Node* next ;

      Node(int d): data(d), next(nullptr)
      {

      }

};

Node* intersection(Node*head1, Node*head2)
{
   Node* temp = head1 ;
   int l1 = 0, l2 = 0 ;
   while(temp!= nullptr)
   {
        temp = temp->next ;
        l1++ ;
   }
   temp = head2 ;
   while(temp!=nullptr)
   {
    temp = temp->next ;
    l2++ ;
   }
   if(l1 > l2)
   {
     int k = l1 - l2 ;
     temp = head1 ;
     while(k--)
     {
        temp = temp->next ;   
     }
     while(temp != nullptr)
   {
    if(temp == head2)
    {
        return temp ;
    }
    temp = temp->next ;
    head2 = head2->next ;
   }
   }
   else
   {
    int k = l2 - l1 ;
    temp = head2 ;
    while(k--)
    {
        temp = temp->next ;
    }
    while(head1 != nullptr)
    {
    if(head1 == temp)
    {
        return temp ;
    }
    head1 = head1->next ;
    temp = temp->next ;
    }
    
   }
  
   return nullptr ;

}
int main()
{
    Node* a1 = new Node(1) ;
    Node* a2 = new Node(2) ;
    Node* b1 = new Node(5) ;
   Node* common = new Node(9) ;
    a1->next = a2 ;
    a2->next = common ;
    b1->next = common ;
    Node* intersect = intersection(a1, b1) ;
    if(intersect != nullptr)
    cout << intersect->data ;
}