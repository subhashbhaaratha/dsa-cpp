#include<iostream>
using namespace std ;
class Node{
    public:
       int data ;
       Node* next ;

    Node(int d):data(d),next(nullptr) 
    {

    }

};
Node* take_input(Node*&tail, int n)
{
    int d;
    cin >> d ;
    Node*head = new Node(d) ;
    tail = head ;
    for(int i = 0 ; i < n-1 ; i++)
    {
        cin >> d ;
        Node* n = new Node(d) ;
        tail->next = n ;
        tail = n ;
    }
    return head ;
}
Node* kAppend(Node*head , int n, int k)
{
    k%=n;
    if(k==0)
    return head ;
    Node*first = head ;
    Node*second = head ;
    for(int i=0;i < k ;i++)
    {
        first = first->next ;
    }
    while(first->next != nullptr)
    {
        first = first->next ;
        second = second->next ;
    }
    first->next = head ;
    Node* newHead = second->next ;
    second->next = nullptr ;
    return newHead ;
}
void print(Node*head)
{
    while(head!=nullptr)
    {
        cout << head->data << " " ;
        head = head->next ;
    }
}

int main()
{
    int n, k ;
    cin >> n ;
    Node*tail = nullptr ;
    Node*head = take_input(tail, n) ;
    cin >> k ;
    head = kAppend(head, n, k );
    print(head) ;


}