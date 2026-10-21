#include<iostream>
using namespace std;
class Node
{
    public:
        int data ;
        Node* next ;
    Node(int d) : data(d), next(nullptr)
    {
    }
};
void insertAtHead(Node*&head, int d)
{
    Node* n = new Node(d) ;
    n->next = head ;
    head = n ;
}
Node* take_input()
{
    int d;
    cin >> d ;
    Node* head = nullptr ;
    while(d != -1)
    {
        insertAtHead(head, d) ;
        cin >> d ;
    }
    return head ;

}

void print(Node*head)
{
    while(head!= nullptr)
    {
        cout << head->data << " -> " ;
        head = head->next ;
    }
}
Node* midpoint(Node*head)
{
    if(head == nullptr || head->next == nullptr)
    return head ;
    Node* slow = head ;
    Node* fast = head->next ;
    while(fast != nullptr && fast->next != nullptr)
    {
        
        fast = fast->next->next ;
        slow = slow->next ;
    }
    return slow;
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
 Node* mergesort(Node*head)
 {
   if(head == nullptr || head->next == nullptr)
   {
    return head ; 
   }
   Node* mid = midpoint(head) ;
   Node* b = mid->next;
   mid->next =nullptr ;
   Node* head1 = mergesort(head) ; 
   Node* head2 = mergesort(b) ;
   Node * c = merge(head1, head2) ;
   return c ;

   
 }

int main()
{
    Node* head = take_input() ;
    print(head) ;
    cout << endl ;
    head = mergesort(head);
    print(head) ;
    
   
   
}