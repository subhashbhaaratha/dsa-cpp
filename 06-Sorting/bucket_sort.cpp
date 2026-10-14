#include<iostream>
#include<vector>
using namespace std;
class Student{

    public:
    string name;
    int marks;
};
void bucket_sort(Student s[],int n)
{
    vector<Student>v[101];//assuming marks are in the range 0to 100
    for(int i=0;i<n;i++)
    {
        int m=s[i].marks;
        v[m].push_back(s[i]);
    }

    for(int i=100;i>=0;i--)
    {
        for(const auto &student:v[i])
        {
            cout<<student.name<<","<<student.marks<<endl;
        }
        
    }
}

int main()
{
    Student s[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].name>>s[i].marks;
    }
    bucket_sort(s,n);

}