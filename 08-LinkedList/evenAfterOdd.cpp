#include<iostream>
using namespace std;
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
void print(Node*head)
{
    while(head!=nullptr)
    {
        cout << head->data << " " ;
        head = head->next ;
    }
}
Node* evenAfterOdd(Node*head)
{
    Node*curr = head ;
    Node* outerprev = nullptr ;
    Node* newtemp = nullptr ;
    Node* innerprev = nullptr ;
    Node*temp = nullptr ;
    while(curr!=nullptr)
    {
        if(((curr->data)&1 ) == 0)
        {
            temp = curr->next ;
            innerprev = curr ;
            while(temp!=nullptr)
            {
                if(((temp->data)&1) == 1)
                {
                    innerprev->next = temp->next ;
                    if(curr != head)
                    {
                        
                        temp->next = curr ;
                        outerprev->next = temp ;
                        outerprev = temp ;
                    }
                    else
                    {
                        temp->next = curr ;
                        head = temp ;
                        outerprev = head ;
                    }
                    temp = innerprev->next ;
                }
                else
                {
                    innerprev = temp ;
                    temp = temp->next ;
                }
                
                
            }
            if(temp == nullptr)
            return head ;
        }
        outerprev = curr ;
        curr = curr->next ;
    }
    return head ;
   
}
int main()
{
    int n;
    cin >> n ;
    Node*tail = nullptr ;
    Node*head = take_input(tail,n) ;
   
    head = evenAfterOdd(head);
    
    print(head) ;
}
