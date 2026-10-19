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
void print(Node* head)
{
    while(head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next ;
    }
}

void insertAtHead(Node*&head, int d)
{
    Node* n = new Node(d) ;
    n->next = head ; 
    head = n ;

}
Node* take_input()
{
    int d ;
    cin >> d ;
    Node* head = nullptr ;
    while(d != -1)
    {
        insertAtHead(head, d) ;
        cin >> d ;
    }
    return head;
}
void take_input2(Node*&head)
{
    int d ;
    cin >> d ;
    while(d != -1)
    {
        insertAtHead(head, d) ;
        cin >> d ;
    }
}
int main()
{
    // Node* head = take_input() ;
    // print(head) ;
    Node* head = nullptr ;
    take_input2(head) ;
    print(head) ;
}