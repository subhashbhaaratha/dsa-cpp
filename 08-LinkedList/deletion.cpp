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

void insertAtHead(Node*&head, int d)
{
    Node* n = new Node(d) ;
    n->next = head ; 
    head = n ;

}
int length(Node* head)
{
    int count = 0 ;
    while(head != nullptr)
    {
        count++ ;
        head = head->next ;
    }
    return count ;
}
void insertAtTail(Node*&head, int d)
{
    if(head == nullptr)
    {
        head = new Node(d) ;
        return ;
    }
    Node* temp = head ;
    while(temp->next != nullptr)
    {
        temp = temp->next ;
    }
    temp->next = new Node(d) ;
}
void insertAtMiddle(Node*&head, int d, int p)
{
    if(head == nullptr || p == 0)
    {
        insertAtHead(head, d) ;
    }
    else if(p >= length(head))
    {
       
        insertAtTail(head, d) ;
    }
    else
    {
        
        int jump = 1 ;
        Node* temp = head ;
        while(jump <= p - 1)
        {
            temp = temp->next ;
            jump++ ;
        }
        Node* n = new Node(d) ;
        n->next = temp->next ;
        temp->next = n ;

    }

}
void print(Node* head)
{
    while(head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next ;
    }
}
void deleteAtHead(Node*&head)
{
    if(head == NULL)
    {
        return ;
    }
    Node* temp = head->next ;
    delete head ;
    head = temp ;
}
void deleteAtTail(Node*&head)
{
    if(head == nullptr)
    {
        return ;
    }
    if(head->next == nullptr)
    {
        delete head ;
        head = nullptr ;
        return ;
    }
    Node* prev = head ;
    while(prev->next->next != nullptr)
    {
        prev = prev->next ;
    }
    Node* temp = prev->next ;
     prev->next = nullptr ;
    delete temp ;
   
   
}
// void deleteAtMiddle(Node*&head, int p)
// {
//     if(head == nullptr)
//     return ;
//     if(p == 0)
//     {
//         deleteAtHead(head) ;
//         return ;
//     }
//     Node* prev = head ;
//     int jump = 1 ;
//     while(jump <= p - 1)
//     {
//         if(prev->next == nullptr)
//         return;
//         prev = prev->next ;
//         jump++ ;
//     }
//     Node* temp = prev->next ;
//     if(temp == nullptr)
//     return ;
//     prev->next = temp->next ;
//     delete temp ;
// }
void deleteAtMiddle(Node*&head, int p)
{
    if(head == nullptr)
    return ;
    if(p == 0)
    {
        deleteAtHead(head) ;
        return ;
    }
    if(p >= length(head))
    return ;
    Node* prev = head ;
    int jump = 1 ;
    while(jump <= p - 1)
    {
        
        prev = prev->next ;
        jump++ ;
    }
    Node* temp = prev->next ;
   
    prev->next = temp->next ;
    delete temp ;
}


int main()
{
    Node* head = nullptr ;
    insertAtHead(head, 4) ;
    insertAtHead(head, 2) ;
    
    insertAtHead(head, 1) ;
     
    insertAtHead(head, 0) ;
    print(head) ;
     cout<<endl;
    print(head) ;
    cout << endl ;
    insertAtMiddle(head, 3, 3) ;
    print(head) ;
    cout << endl ;
    insertAtMiddle(head, 5, 5) ; 
    print(head) ;
    cout << endl ;
    insertAtTail(head, 6) ;

    
    print(head) ;
    cout << endl ;
    deleteAtHead(head) ;
    print(head) ;
    cout << endl ;

    deleteAtMiddle(head,2) ;
    print(head) ;
    cout << endl ;

    deleteAtTail(head) ;
    print(head) ;
    cout << endl ;

}