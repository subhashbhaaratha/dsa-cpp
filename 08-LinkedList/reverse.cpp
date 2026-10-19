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
void reverse(Node*&head)
{
    if(head == nullptr)
    return ;
    Node* prev = nullptr ;
    Node* C = head ;
    Node* N = nullptr ;
    while(C != nullptr)
    {
        N = C->next ;
        C->next = prev ;
        prev = C ;
        C = N ;
    }
    head = prev ;    
}
void print(Node*head)
{
    while(head!= nullptr)
    {
        cout << head->data << " -> " ;
        head = head->next ;
    }
}
int main()
{
    Node* head = take_input() ;
    print(head);
    cout << endl ;
    reverse(head) ;
    print(head) ;
    cout << endl ;
}