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
Node* reverseRecursive(Node*head)
{
    if(head->next == nullptr)
    return head ;
    Node* shead = reverseRecursive(head->next) ;
    Node* temp = head->next ;
   
    head->next = nullptr ;
    temp->next = head ;
    return shead ;
}


int main()
{
    Node* head = take_input() ;
    print(head);
    cout << endl ;
    head = reverseRecursive(head) ;
    print(head) ;
    cout << endl ;
}