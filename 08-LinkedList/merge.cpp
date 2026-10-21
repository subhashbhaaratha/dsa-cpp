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
void insertAtTail(Node*&c , Node*&tail , int d)
{
    if(tail == nullptr)
    {
        c = new Node(d);
        tail = c ;
    }
    else
    {
        tail->next = new Node(d) ;
        tail = tail->next ;
    }
}

void merge(Node* head1, Node* head2, Node*&c, Node*&tail)
{
   
    if(head1 == nullptr )
    {
        while(head2 != nullptr)
        {
           insertAtTail(c,tail,head2->data) ;
           head2 = head2->next ;
        }
        return ;
    }
     if(head2 == nullptr )
    {
        while(head1 != nullptr)
        {
            insertAtTail(c,tail,head1->data) ;
            head1 = head1->next ;
            
        }
        return ;
    }
    if(head1->data <= head2->data)
     {
        insertAtTail(c,tail,head1->data) ;
        head1 = head1->next ;
     }
     else
     {
        insertAtTail(c,tail,head2->data) ;
        head2 = head2->next ;
        
     }
   return  merge(head1,head2,c,tail) ;
}
Node* mergeInPlace(Node* head1, Node* head2)
{
   
    if(head1 == nullptr )
    {
       
      return head2 ;

    }
    if(head2 == nullptr)
    {
      return head1 ;
    }
    if(head1->data <= head2->data)
    {
       Node* shead = mergeInPlace(head1->next,head2) ; 
       head1->next = shead ;
       return head1 ;
    }
    else
    {
       Node* shead = mergeInPlace(head1,head2->next) ; 
       head2->next = shead ;
       return head2 ;
    }
}

int main()
{
    Node* head1 = take_input() ;
    Node* head2 = take_input() ;
    print(head1) ;
    cout << endl ;
    print(head2) ;
    cout << endl ;
    // Node* tail = nullptr ;
    // merge(head1, head2, c,tail) ; 
    Node* newHead = mergeInPlace(head1, head2) ;
    print(newHead) ;
    cout << endl ;
   
   
}