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
Node* take_input(int n)
{
    int d ;
    cin >> d ;
    Node* head = new Node(d) ;
    Node* tail = head ;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        cin >> d ;
        Node* n = new Node(d) ;
        tail->next = n ;
        tail = n ;
    }
    return head ;
}
void print(Node* head)
{
    while(head != nullptr)
    {
        cout << head->data << " " ;
        head = head->next ;
    }
}

Node* insertion_sort(Node*head)
{
    if(head->next == nullptr)
    {
        return head ;
    }
   Node* outercurr = head->next ;
   Node* outerprev = head ;
   Node* innercurr = nullptr ;
   Node* innerprev = nullptr ;
   Node* N = nullptr ;
   while(outercurr != nullptr)
   {
     innercurr = head ;
     while(innercurr != outercurr)
     {
        if(outercurr->data < innercurr->data)
        {
            if(innercurr == head)
            {
                N = outercurr->next ;
                outercurr->next = innercurr ;
                outerprev->next = N ;
                head = outercurr ;
                break ;
            }
            else
            {
                N = outercurr->next ;
                outercurr->next = innercurr ;
                innerprev->next = outercurr ;
                outerprev->next = N ;
                break ;
            }
        }

        innerprev = innercurr ;
        innercurr = innercurr->next ;
     }
     if(innercurr == outercurr)
     {
        outerprev = outercurr ;
        outercurr = outercurr->next ;
     }
     outercurr = outerprev->next ;
   }
   return head ;
}

int main()
{
    int n ;
    cin >> n ;
    Node*head = take_input(n) ;
    head = insertion_sort(head) ;
    print(head) ;
 

}