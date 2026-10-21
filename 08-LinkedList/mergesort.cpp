#include<iostream>
using namespace std;
class Node{
      
     public : 
       int data ;
       Node* next ;
    
    Node(int d): data(d) , next(nullptr)
    {

    }
};
 Node* take_input(Node*&tail)
 {
    Node* head = nullptr ;
    int d;
    cin >> d ;
    if(d == -1)
    return head ;
    head = new Node(d) ;
    tail = head ;
    cin >> d ;
    while(d != -1)
    {
        tail->next = new Node(d) ;
        tail = tail->next ;
        cin >> d ;
    }
    return head ;

 }
 void print(Node* head)
 {
    if(head == nullptr)
    return ;
    while(head != nullptr)
    {
        cout << head->data << " -> " ;
        head = head->next ;
    }
 }
 Node* midPoint(Node*head, Node*tail)
 {
    Node* slow = head ;
    Node* fast = head->next ;
    while(fast != tail && fast != tail->next)
    {
        fast = fast->next->next ;
        slow = slow->next ;
    }
    return slow ;
 }
 Node* merge(Node* head1,Node* head2)
 {
    if(head1 == nullptr)
    {
        return head2 ;
    }
    if(head2 == nullptr)
    {
        return head1 ;
    }
    if(head1->data <= head2->data)
    {
        head1->next = merge(head1->next, head2) ;
        return head1 ;
    }
    else
    {
        head2->next = merge(head1, head2->next) ;
        return head2 ;
    }



 }
 Node* mergesort(Node*head, Node*tail)
 {
    if(head == tail)
    {
        return head ;
    }
    Node* mid = midPoint(head, tail) ;
    Node* temp = mid->next ;
    mid->next = nullptr ;
    Node* head1 = mergesort(head, mid) ;
    Node* head2 = mergesort(temp, tail) ;
    return merge(head1,head2) ;
 }

int main()
{
   Node* tail = nullptr ;
   Node* head = take_input(tail) ;
   print(head) ;
   Node* newhead = mergesort(head,tail) ;
   cout << endl ;
   print(newhead) ;

  
}