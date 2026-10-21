#include<iostream>
using namespace std ;
class Node{
    public:
        int data ;
        Node* next ;

    Node(int d): data(d) , next(nullptr)
    {

    }
};
Node* take_input(Node*&tail, int n)
{
    if(n == 0)
    return nullptr ;
    int d ;
    cin >> d ;
    Node* head = new Node(d) ;
    tail = head ;
    for(int i = 0 ;i < n-1 ; i++)
    {
        cin >> d ;
        Node* n = new Node(d);
        tail->next = n ;
        tail = n ;   
    } 
    return head ;
}

Node* reverse(Node*head, int n, int k)
{
    Node* newhead = nullptr ;
    Node* prev = nullptr ;
    Node* curr = head ;
    Node* groupStart = head ;
    Node* nextNode = nullptr;
    Node* previousGroupTail = nullptr ;
    for(int i = 0 ; i < n/k ; i++)
    {
        int j = k ;
       
        while(j--)
        {
            nextNode = curr->next ;
            curr->next = prev ; 
            prev = curr ;
            curr = nextNode ;
        }
        if(i == 0)
        {   
            newhead = prev ;
            groupStart->next = curr ; 
            prev = groupStart ;
            groupStart = curr ;
            continue ;
        }
        previousGroupTail = groupStart->next ;
        groupStart->next = curr ; 
        previousGroupTail->next = prev;
        prev = groupStart ;
        groupStart = curr ;
    }
    return newhead ;
}
void print(Node*head)
{
    while(head != nullptr)
    {
        cout << head->data << " ";
        head = head->next ;
    }
}
int main()
{
    int n , k ;
    cin >> n >> k ;
    Node*tail = nullptr ;
    Node*head = take_input(tail, n) ;
    head = reverse(head, n, k) ;
    print(head) ;

}