#include <iostream>
#include "custom_vector.h"
using namespace std;
int main()
{
    Vector V;
    V.push_back(1);
    V.push_back(2);
    V.push_back(3);
    V.pop_back();
    V.push_back(10);
     V.push_back(10);
      V.push_back(10);
    cout<<"Capacity:"<<V.capacity()<<endl;
   cout<<"Size:"<< V.size();
}