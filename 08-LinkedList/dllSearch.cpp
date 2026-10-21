#include<iostream>
using namespace std;
class Node{
    public:
     int data ; 
     Node* next ;
     Node* prev ;

     Node(int d) : data(d), next(nullptr), prev(nullptr)
     {

     } 
};

void insertAtHead(Node*&head, int d)
{
    if(head == nullptr)
    {
        head = new Node(d) ;
        return ;
    }

    Node* n = new Node(d) ;
    n->next = head ;
    head->prev = n ;
    head = n ;
}
void insertAtTail(Node*&head, int d)
{
    if(head == nullptr)
    {
        head = new Node(d) ;
       
        return ;
    }
    Node* tail = head ;
    while(tail->next != nullptr)
    {
        tail = tail->next ;
    }
    Node* n = new Node(d) ;
    tail->next = n ;
    n->prev = tail ;
    tail = n ;
}
int length(Node* head)
{
    if(head == nullptr)
    return 0 ;
    Node* temp = head ;
    int count = 0 ;
    while(temp!= nullptr)
    {
        count ++ ;
        temp = temp->next ;
    }
    return count ;
    
}

void insertAtMiddle(Node*&head, int p , int d)
{
    if(head == nullptr || p == 0)
    {
        insertAtHead(head,d) ;
        return ;
    }
    Node* temp = head ;
    for(int i = 0 ; i < p - 1 && temp->next != nullptr ; i++)
    {
        temp = temp->next ;
    }
    if(temp->next == nullptr)
    {
        Node* n = new Node(d) ;
        temp->next = n ;
        n->prev = temp ;
        return ;
    }
    Node* n = new Node(d) ;
    n->next = temp->next ;
    temp->next->prev = n ; 
    temp->next = n ;
    n->prev = temp ;
}
void print(Node* head)
{
    if(head == nullptr)
    return ;
    while(head != nullptr)
    {
        cout  <<  head->data << " <-> " ;
        head = head->next ;
    }
}
void printBackwards(Node* head)
{
    while(head->next!= nullptr)
    {
        head = head->next ;
    }
    while(head!= nullptr)
    {
        cout << head->data << " -> " ;
        head = head->prev ;
    }
}
bool searchNode(Node*head, int key)
{
    if(head == nullptr)
    {
        return false ;
    }
    while(head!= nullptr)
    {
        if(head->data == key)
        {
            return true ;
        }
        head = head->next ;
    }
    return false ;


}

int main()
{
    Node* head = nullptr ;
    insertAtHead(head, 7) ; 
    insertAtHead(head, 4) ; 
    insertAtHead(head, 3) ;
    insertAtHead(head, 2) ;
    insertAtHead(head, 1) ; 
    insertAtTail(head, 8) ;
    insertAtTail(head, 9) ;
    print(head) ;
    cout << endl ;
    insertAtMiddle(head,4,5) ;
    insertAtMiddle(head,5,6) ;
    insertAtMiddle(head,10,10) ;
    insertAtMiddle(head,12,23) ;
    insertAtMiddle(head,0,0) ;

    print(head) ;
    cout << endl ;
    printBackwards(head) ;
    cout << endl ;
    cout << searchNode(head, 22) ;
     

}