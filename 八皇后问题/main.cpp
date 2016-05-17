#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int vis[110][110];
int output()
{
    int i,j;
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            printf("%d ",vis[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int check(int x,int y)
{
    int i,j;
    if(x==1) return 1;
    for(i=1;i<x;i++)
    {
        if(vis[i][y]==1)
            return 0;
    }
    for(i=1;i<y;i++)
    {
        if(vis[x][i]==1)
            return 0;
    }
    for(i=1;i<x;i++)
    {
        if(vis[i][x+y-i]==1||vis[i][i+y-x]==1)
            return 0;
    }
    return 1;
}
int go(int x)
{
    int i,j;
    if(x>8)
    {
        output();
        return 0;
    }
    for(i=1;i<=8;i++)
    {
        vis[x][i]=1;
        if(check(x,i))
        {
            go(x+1);
        }
        vis[x][i]=0;
    }

    return 0;
}
int main()
{
    memset(vis,0,sizeof(vis));
    go(1);
   // cout << "Hello world!" << endl;
    return 0;
}
