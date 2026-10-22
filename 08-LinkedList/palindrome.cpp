#include<iostream>
using namespace std ;
class Node{
    public:
        int data ;
        Node* next ;


    Node(int d) : data(d), next(nullptr)
    {

    }
};

Node* take_input()
{
    int d ; 
    cin >> d ;
    Node* head = new Node(d) ;
    Node*tail = head ;
    cin >> d ;
    while(d != -1)
    {
        Node* n = new Node(d) ;
        tail->next = n ;
        tail = n ;
        cin >> d ;
    }
    return head ;
}
bool palindrome(Node* head)
{
    if(head == nullptr)
    return false ;
    if(head->next == nullptr)
    {
        return true ;
    }
    Node*p1 = head ;
    int len = 0 ;
    while(p1 != nullptr)
    {
        len++ ;
        p1 = p1->next ;
    }
    Node* fast = head->next ;
    Node* mid = head ;
    Node* prev = nullptr ;
    while(fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next ;
        prev = mid ;
        mid = mid->next ;
    }
    Node* curr = nullptr ;
    Node*temp = nullptr;
    Node* N = nullptr ;
    if((len&1) == 1)
    {
        if(prev->data != mid->next->data)
        {
            return false ;
        }
        curr = mid->next ;
        temp = mid ;
        while(curr != nullptr)
        {
            N = curr->next ;
            curr->next = temp ;
            temp = curr ; 
            curr = N ;
        }
        while(head != mid)
        {
            if(head->data != temp->data)
            return false ;
            head = head->next ;
            temp = temp->next ;
        }
        return true ;
    }
    else
    {

         if(mid->data != mid->next->data)
        {
            return false ;
        }
        curr = mid->next->next ;
        temp = mid->next ;
        while(curr != nullptr)
        {
            N = curr->next ;
            curr->next = temp ;
            temp = curr ; 
            curr = N ;
        }
        while(head != mid)
        {
            if(head->data != temp->data)
            return false ;
            head = head->next ;
            temp = temp->next ;
        }
        return true ;
    }
}
int main()
{
    Node*head = take_input() ;
    

    cout << palindrome(head) ;
}