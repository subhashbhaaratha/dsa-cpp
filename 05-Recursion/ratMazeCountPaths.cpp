#include<iostream>
using namespace std;
int ratInMaze(char maze[10][10],int i,int j,int m,int n)
{
    if(i==m&&j==n)
    {
        
       
        return 1;
    }

    if(i>m||j>n)
    return 0;
    if(maze[i][j]=='X')
    return 0;
   
   int rightPaths=ratInMaze(maze,i,j+1,m,n);
    int downPaths=ratInMaze(maze,i+1,j,m,n);
    
    return rightPaths+downPaths;
    
}
int main()
{
    char maze[10][10]={"0000","00X0","000X","0X00"};
   
    int m=4,n=4;
    int ans=ratInMaze(maze,0,0,m-1,n-1);
    cout<<ans;
    
    return 0;
}