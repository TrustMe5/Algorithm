#include <iostream>
#include<queue>
#include<string.h>
#include<cmath>
using namespace std;
int m,n,flag;
int step[11000],vis[10010],path[10010];
int check(int x)
{
    int i;
    for(i=2; i<=int(sqrt(double(x))); i++)
    {
         if(x%i==0)
            return 0;
    }
    return 1;
}
void bfs(int x)
{
    int s,i,j;
    memset(step,0,sizeof(step));
    memset(vis,0,sizeof(vis));
    queue<int>q;
    while(!q.empty())
        q.pop();
    q.push(x);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        if(x==n)
        {
            flag=1;
            return;
        }
        int a=x/1000;
        int b=(x-a*1000)/100;
        int c=(x-a*1000-b*100)/10;
        int d=x-a*1000-b*100-c*10;
        for(i=0; i<8; i++)
        {
            if(i==0)
            {
                for(j=1; j<10; j++)
                {
                    if(a+j<10)
                    {
                        s=(a+j)*1000+b*100+c*10+d;
                    }
                    if(check(s)&&!vis[s])
                    {
                        vis[s]=1;
                        step[s]=step[x]+1;
                         path[s]=x;
                        q.push(s);
                    }
                }
            }
            if(i==1)
            {
                for(j=1; j<10; j++)
                {
                    if(b+j<10)
                        s=a*1000+(b+j)*100+c*10+d;
                    if(check(s)&&!vis[s])
                    {
                        vis[s]=1;
                        step[s]=step[x]+1;
                        path[s]=x;
                        q.push(s);
                    }
                }
            }
            if(i==2)
            {
                for(j=1; j<10; j++)
                {
                    if(b-j>=0)
                        s=a*1000+(b-j)*100+c*10+d;
                    if(check(s)&&!vis[s])
                    {
                        vis[s]=1;
                        step[s]=step[x]+1;
                         path[s]=x;
                        q.push(s);
                    }
                }
            }
            if(i==3)
            {
                for(j=1; j<10; j++)
                {
                    if(c+j<10)
                        s=a*1000+b*100+(c+j)*10+d;
                    if(check(s)&&!vis[s])
                    {
                        vis[s]=1;
                        step[s]=step[x]+1;
                         path[s]=x;
                        q.push(s);
                    }
                }
            }
            if(i==4)
            {
                for(j=1; j<10; j++)
                {
                    if(c-j>=0)
                        s=a*1000+b*100+(c-j)*10+d;
                    if(check(s)&&!vis[s])
                    {
                        vis[s]=1;
                        step[s]=step[x]+1;
                         path[s]=x;
                        q.push(s);
                    }
                }
            }
            if(i==5)
            {
                for(j=1; j<10; j++)
                {
                    if(d+j<10)
                        s=a*1000+b*100+c*10+d+j;
                    if(check(s)&&!vis[s])
                    {
                        vis[s]=1;
                        step[s]=step[x]+1;
                         path[s]=x;
                        q.push(s);
                    }
                }
            }
            if(i==6)
            {
                for(j=1; j<10; j++)
                {
                    if(d-j>=0)
                        s=a*1000+b*100+c*10+d-j;
                    if(check(s)&&!vis[s])
                    {
                        vis[s]=1;
                        step[s]=step[x]+1;
                         path[s]=x;
                        q.push(s);
                    }
                }
            }
            if(i==7)
            {
                for(j=1; j<10; j++)
                {
                    if(a-j>0)
                        s=(a-j)*1000+b*100+c*10+d;
                    if(check(s)&&!vis[s])
                    {
                        vis[s]=1;
                        step[s]=step[x]+1;
                         path[s]=x;
                        q.push(s);
                    }
                }
            }
        }
    }
}
int main()
{
    int T,i,j;
    cin>>T;
    while(T--)
    {
        flag=0;
        cin>>m>>n;
        bfs(m);
        if(flag==1)
        {
            cout<<step[n]<<endl;
        }

        else cout<<"Impossible"<<endl;
    }
    return 0;
}
