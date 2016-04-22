/*************************************************************************
	> File Name: code.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月22日 星期五 11时17分42秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#define inf 999999
using namespace std;
int n,m,map[110][110],cost[110][110],vis[110][110];
void floyd()
{
    int i,j,k,s,e;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cost[i][j]=map[i][j];
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]>(cost[i][k]+cost[k][j]))
                {
                    cost[i][j]=cost[i][k]+cost[k][j];
                }
            }
        }
    }
    cout<<"input two points:";
    cin>>s>>e;
    cout<<cost[s][e]<<endl;
}
int main()
{
    int i,j,a,b,c;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j) map[i][j]=0;
            else map[i][j]=inf;
        }
    }
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        if(c<map[a][b])
        {
            map[a][b]=map[b][a]=c;
        }
    }
    floyd();
    
    
    return 0;
}
