#include<iostream>
using namespace std ;
class Node
{
    public:
        int data ;
        Node* next ;
    Node(int d) : data(d), next(nullptr)
    {
    }
};

void insertAtHead(Node*&head ,int d)
{
    if(head == nullptr)
    {
        Node* n = new Node(d) ;
        head = n ;
        n->next = head ;
        return ;
    }
    Node* temp = head ;
    while(temp->next !=head)
    {
        temp = temp->next ;
    }

    Node* n = new Node(d) ;
    n->next = head ; 
    head = n ;
    temp->next = head ;


} 
void insertAtTail(Node*&head, int d)
{

 if(head == nullptr)
 {
    insertAtHead(head, d) ;
    return ;
 }
 Node* temp = head ;
 while(temp->next != head)
 {
    temp = temp->next ;
 }
 Node* n =new Node(d) ;
 temp->next = n ;
 n->next = head  ;
}
void insertAtMiddle(Node*&head, int p, int d)
{
    if(head == nullptr || p == 0)
    {
        insertAtHead(head,d) ;
        return ;
    }
    Node* temp = head ;
    for(int i = 0 ; i < p - 1 && temp->next != head ; i++)
    {
        temp = temp->next ;
    }
    if(temp->next == head)
    {
        Node* n = new Node(d) ;
        n->next = head ;
        temp->next = n ;
        return ;
    }
    Node* n = new Node(d) ;
    n->next = temp->next ;
    temp->next = n ;
}
void print(Node*head)
{
    if(head == nullptr)
    return;
   
     Node*temp = head ;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next ;
    }
    while(temp != head);
    cout << "backto ( " << head->data << " )" << endl ;

}


void deleteNode(Node*&head, int d)
{
    if(head == nullptr)
    return ;
    Node* temp = head ;
    Node* del = nullptr ;
    do 
    {
        if(temp->data == d)
        {
            del = temp ;
        }
        temp = temp->next ;
    }
    while(temp != head);
    if(del == nullptr)
    {
        return ;
    }
    if(del == head)
    {
        if(head->next == head)
        {
            delete head ;
            head = nullptr ;
            return ; 
        }
        head = head->next ;

    }
    Node* prev = head ;
    while(prev->next != del)
    {
        prev = prev->next ;
    }
    prev->next = del->next ;
    delete del ;


}





int main()
{
    Node* head = nullptr ;
    insertAtHead(head,7) ;
    insertAtHead(head,4) ;
    insertAtHead(head,3) ;
    insertAtHead(head,2) ;
    insertAtHead(head,1) ;
    
    insertAtTail(head,8) ;
    
    insertAtTail(head,9) ;
    insertAtMiddle(head,4,5);
     
    insertAtMiddle(head,5,6);
     
    insertAtMiddle(head,9,10);
    
    insertAtMiddle(head,11,23);
     print(head) ;
     cout<<endl ;
     deleteNode(head, 5) ;
      print(head) ;
     cout<<endl ;
     deleteNode(head, 1) ;
      print(head) ;
     cout<<endl ;
     deleteNode(head, 7) ;
      print(head) ;
     cout<<endl ;
    
     
     
    

     


}