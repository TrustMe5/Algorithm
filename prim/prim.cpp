/*************************************************************************
	> File Name: prim.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月28日 星期一 20时18分58秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#define inf 999999
using namespace std;
int lowcost[100020],vis[110],map[110][110];
int m,n,i,j,pos;
void prim()
{
    int sum=0;
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    for(i=1;i<=m;i++)
    {
        lowcost[i]=map[1][i];
    }
    for(i=1;i<m;i++)
    {
        int min=inf;
        for(j=1;j<=m;j++)
        {
            if(!vis[j]&&min>lowcost[j])
            {
                min=lowcost[j];
                pos=j;
            }
        }
        sum+=min;
        vis[pos]=1;
        for(j=1;j<=m;j++)
        {
            if(!vis[j]&&lowcost[j]>map[pos][j])
            {
                lowcost[j]=map[pos][j];
            }
        }
    }
    cout<<sum<<endl;
}
int main()
{
    int a,b,c;
    while(cin>>m>>n)
    {
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(i==j) map[i][j]=map[j][i]=0;
                else map[i][j]=map[j][i]=inf;
            }
        }
        while(n--)
        {
            cin>>a>>b>>c;
            if(c<map[a][b])
            map[a][b]=map[b][a]=c;
        }
        prim();
    }
return 0;
}
