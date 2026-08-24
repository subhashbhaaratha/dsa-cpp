#include<iostream>
#include<algorithm>
using namespace std;
struct Student{
        string name;
        int marks;
    };
int main(){
    
    Student arr[]={{"Alice",25},{"Bob",17},{"Charlie",29}};
    sort(arr,arr+3,[](const Student &x,const Student &y){
        return x.name>y.name;
    });
    for(int i=0;i<3;i++){
        cout<<arr[i].name<<" "<<arr[i].marks<<endl;
    }
}
