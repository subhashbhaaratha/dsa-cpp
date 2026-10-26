#include<iostream>
using namespace std ;
class Node{
    public :
     int data ;
     Node* next ;

    Node(int d) : data(d) , next(nullptr)
    {}
};
void insertAtTail(Node*&head, Node*&tail, int d)
{
    if(head == nullptr)
    {
        head = new Node(d) ;
        tail = head ;
        return ;
    }
    Node* newNode = new Node(d) ;
    tail->next = newNode ;
    tail = newNode ;
}
void deleteAtHead(Node*&head, Node*&tail)
{
    if(head == nullptr)
    {
        return ;
    }
    Node* oldHead = head ;
    if(head == tail)
    {
        head = nullptr ;
        tail = nullptr ;
    }
    else
    {
        head = head->next ;
    }
    
    delete oldHead ;

}
class Queue{
    Node* head ;
    Node* tail ;
public:
    Queue()
    {
        head = nullptr ;
        tail = nullptr ;
    }
    bool empty()
    {
        return head == nullptr ;
    }
    void push(int d)
    {
        insertAtTail(head, tail, d) ;
    }
    void pop()
    {
        if(!empty())
        {
            deleteAtHead(head, tail) ;
        }
    }
    int front()
    {
        if(!empty())
        {
            return head->data ;
        }
        return -1 ;
    }
    ~Queue()
    {
        while(!empty())
        {
            pop() ;
        }
    }


};

int main()
{
    Queue q ;
    for(int i = 1; i < 5 ; i++)
    {
        q.push(i) ;
    }
    while(!q.empty())
    {
        cout << q.front() << " " ;
        q.pop() ;
    }

}