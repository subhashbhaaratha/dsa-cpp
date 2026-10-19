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

Node* kthNodeFromEnd(Node* head, int k)
{
    if(head == nullptr || k == 0)
    return nullptr ;
    Node* fast = head ;
    Node* slow = head ;
    
    for(int jumps = 1; jumps <= k  ; jumps++)
    {
        if(fast == nullptr)
        return nullptr ;
        fast = fast->next ;
    }
    
    while(fast != nullptr)
    {
        fast = fast->next ;
        slow = slow->next ;
    }
    return slow ;
}

int main()
{
    Node* head = take_input() ;
    print(head);
    cout << endl ;
    cout << "enter k: " ;
    int k ;
    cin >> k ;
    Node* kthNode = kthNodeFromEnd(head, k) ;
    if(kthNode != nullptr)
    cout << kthNode->data ;
   
   
}