/*************************************************************************
	> File Name: code.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月21日 星期四 16时03分07秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#define inf 99999999
using namespace std;
int n,m,map[11000][11000],dist[1100000];
void dijkstra(int num)
{
    int i,j,vis[110000],pos;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
    {
        dist[i]=map[1][i];
    }
    vis[1]=1;
    for(i=2;i<=n;i++)
    {
        int min=inf;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&dist[j]<min)
            {
                min=dist[j];
                pos=j;
            }
        }
        vis[pos]=1;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&dist[j]>min+map[pos][j])
            {
                dist[j]=min+map[pos][j];
            }
        }
    }
    cout<<dist[n]<<endl;
    cout<<endl;
}
int main()
{
    int i,j,k,T,a,b,c;
    cin>>T;
    for(k=1;k<=T;k++)
    {
        cin>>n>>m;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==j) map[i][j]=0;
                else  map[i][j]=inf;
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
        dijkstra(k);
    }
    return 0;
}
