#include<iostream>
using namespace std;
bool isSafe(char board[][10],int i,int j,int n)
{
    
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
        return false;
    }
    int x=i;
    int y=j;
    while(x>=0&&y>=0)
    {
        if(board[x][y]==1)
        return false;
    x--;
    y--;
    }
     x=i;
    y=j;
    while(x>=0&&y<n)
    {
        if(board[x][y]==1)
        return false;
    x--;
    y++;
    }
    return true;


}
int  solveNQueen(char board[][10],int i,int n)
{
    if(i==n)
    {
        return 1;
    }
    int count=0;
    for(int j=0;j<n;j++)
    {
        if(isSafe(board,i,j,n))
       {
        board[i][j]=1;
       count+=solveNQueen(board,i+1,n);
        
        board[i][j]=0;
       }
    }
    return count;
}
int main()
{
    char board[10][10]={0};
    int n;
    cin>>n;
    cout<<solveNQueen(board,0,n);
}