#include<iostream>
#include<vector>
using namespace std ;
class Stack{
    
    vector<int> v ;
    vector<int> vMin ;
    vector<int> vMax ;
    public:
        void push(int d)
        {
            v.push_back(d) ; 
            if(vMin.empty())
            {
                vMin.push_back(d) ;
                vMax.push_back(d) ;
                return ;
            }
            else 
            {
                if(d >= vMin.back())
                {
                    vMin.push_back(vMin.back());

                }
                else
                {
                    vMin.push_back(d) ;
                }
            }
                if(d > vMax.back())
                {
                    vMax.push_back(d) ;
                }
                else
                {
                    vMax.push_back(vMax.back()) ;
                }
        }

        void pop()
        {
            v.pop_back() ;
            vMin.pop_back() ;
            vMax.pop_back() ;
        }
        int top()
        {
            return v.back() ;
        }
        int getMin()
        {
            return vMin.back() ;
        }
        int getMax()
        {
            return vMax.back() ;
        }
        bool isEmpty()
        {
            return v.size() == 0 ;
        }
};
int main()
{
    Stack s ;
    for(int i = 0 ; i < 6 ; i++)
    {
        s.push(i*i) ;
    }
    s.push(7) ;
    s.push(-1) ;
    s.pop();
    cout << " Min : " <<  s.getMin() << endl;
    cout << " Max : " << s.getMax() << endl ;

    while(!s.isEmpty())
    {
        cout << s.top()  <<  " ";
        s.pop() ;
    }

}
