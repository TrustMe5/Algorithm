/*************************************************************************
	> File Name: queen.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月29日 星期二 19时25分00秒
 ************************************************************************/

#include<iostream>
using namespace std;
int vis[110][110];
void output()
{
int i,j;
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }
}
int check(int x,int y)
{
int i,j;
    if(x==1)
    return 1;
    for(i=1;i<x;i++)
    {
        if(vis[i][y]||vis[i][x+y-i]||vis[i][i+y-x])
        return 0;
    }
    for(i=1;i<y;i++)
    {
        if(vis[x][i])
        return 0;
    }
    return 1;
}
int go(int n)
{
int i,j;
    if(n>8)
    {
        output();
        return 0;
    }
    else
    {
        for(i=1;i<=8;i++)
        {
            vis[n][i]=1;
            if(check(n,i))
            {
                go(n+1);
            }
            vis[n][i]=0;
        }
    }
}
int main()
{
    go(1);
    return 0;
}
