// #include<iostream>
// using namespace std;
// bitset<30> col,d1,d2;
// void solve(int n,int r,int &ans)
// {
//     if(r==n)
//     {
//         ans++;
//         return;
//     }
//     for(int c=0;c<n;c++)
//     {
//         if(!col[c]&&!d1[r+c]&&!d2[r-c+n-1])
//         {
//             col[c]=d1[r+c]=d2[r-c+n-1]=1;
//             solve(n,r+1,ans);
//             col[c]=d1[r+c]=d2[r-c+n-1]=0;
//         }
//     }
    
// }


// int main()
// {
//     int n;
//     cin>>n;
//     int ans=0;
//     solve(n,0,ans);
//     cout<<ans;
// }
#include<iostream>
using namespace std;
bitset<30> col,d1,d2;
int solve(int n,int r)
{
    if(r==n)
    {
       
        return 1;
    }
    int count =0;
    for(int c=0;c<n;c++)
    {
        if(!col[c]&&!d1[r+c]&&!d2[r-c+n-1])
        {
            col[c]=d1[r+c]=d2[r-c+n-1]=1;
            count+=solve(n,r+1);
            col[c]=d1[r+c]=d2[r-c+n-1]=0;
        }
    }
    return count;
    
}


int main()
{
    int n;
    cin>>n;
    
    cout<<solve(n,0);
   
}