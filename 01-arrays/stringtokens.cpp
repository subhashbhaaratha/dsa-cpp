// #include <iostream>
// #include <cstring>
// using namespace std;
// char *mystrtok(char *str, char delim)
// {

//     static char *input = NULL;
//     if (str != NULL)
//     {
//         input = str;
//     }

//     if (input == NULL)
//     {
//         return NULL;
//     }

//     char *output = new char[strlen(input) + 1];
//     int i = 0;
//     for (; input[i] != '\0'; i++)
//     {
//         if (input[i] != delim)
//             output[i] = input[i];
//         else
//         {
//             output[i] = '\0';
//             input = input + i + 1;
//             return output;
//         }
//     }

//     output[i] = '\0';
//     input = NULL;
//     return output;
// }
// int main()
// {

//     char s[100] = "Today, is my, day";
//     char *ptr = mystrtok(s, ',');
//     cout << ptr << endl;
//     while (ptr != NULL)
//     {

//         ptr = mystrtok(NULL, ',');
//         cout << ptr << endl;
//     }
// }

//without dynamic array
#include<iostream>
using namespace std;

char* mystrtok(char* str ,char delim){
    static char* input = nullptr;
    if(str!=nullptr){
        input=str;
    }
    if(input==nullptr){
        return nullptr;
    }

    char*tokenstart =input;
    while(*input!='\0'){
        if(*input==delim){
            *input='\0';
            input=input+1;
            return tokenstart;
        }
        input++;
    }
   
    input=nullptr;
    return tokenstart;



}


int main(){
    char s[100]="Today,is my ,day";
    char*ptr=mystrtok(s,',');
    cout<<ptr<<endl;
    while(ptr!=nullptr){
        ptr=mystrtok(nullptr,',');
        cout<<ptr<<endl;
    }
    return 0;
}