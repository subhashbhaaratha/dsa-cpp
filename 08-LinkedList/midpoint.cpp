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

void midpoint(Node*head)
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
    cout << slow->data;
}

int main()
{
    Node* head = take_input() ;
    print(head);
    cout << endl ;
    midpoint(head) ;
   
}