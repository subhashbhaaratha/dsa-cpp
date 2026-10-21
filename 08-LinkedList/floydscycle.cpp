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
bool floydscycle(Node* head)
{
    Node* slow = head ;
    Node* fast = head ;
    while(fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next ;
        slow = slow->next ;
        if(fast == slow)
        {
            return true ;
        }
    }
    return false ;

}
void removeFloydsCycle(Node *head)
{
    Node* slow = head ;
    Node* fast = head ;
     while(fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next ;
        slow = slow->next ;
        if(fast == slow)
        {
            break ;
        }
    }
    if(fast == nullptr || fast->next == nullptr)
    {
        cout << "No Cycle detected" ;
        return ;
    }
    slow = head ;
    while(fast!=slow)
    {
        fast = fast->next ; 
        slow = slow->next ;
    }
    while(fast->next!=slow)
    {
        
        fast = fast->next ;
    }
    fast->next = nullptr ;
   

}
int main()
{
    Node*head = take_input() ;
    Node* joint = head ;
    //joint = joint->next->next ;
    Node*tail = head ;
    while(tail->next != nullptr)
    {
        tail = tail->next ;
    }
    tail->next = joint ;
    if(floydscycle(head))
    cout << "true" << endl ;
    else
    cout << "false" << endl ;
    removeFloydsCycle(head) ;
     if(floydscycle(head))
    cout << "true" << endl ;
    else
    cout << "false" << endl ;
    print(head) ;


}