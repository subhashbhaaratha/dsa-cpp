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
        cout << "inside else if  p>=length" ;
        insertAtTail(head, d) ;
    }
    else
    {
        cout << "inside else"  ;
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

int main()
{
    Node* head = nullptr ;
    insertAtHead(head, 4) ;
    insertAtHead(head, 2) ;
    insertAtHead(head, 1) ;
    insertAtHead(head, 0) ;
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

}