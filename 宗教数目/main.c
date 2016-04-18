#include<stdio.h>
#include<string.h>
#include <queue>
#include<stdlib.h>
using namespace std;
struct dian
{
    struct bian *first;
} dian[110];
struct bian
{
    int data;
    struct bian *next;
};
int main()
{
    int n,k,m,t,i,u,v;
    int vis[110];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d",&k,&m,&t);
        for(i=0; i<k; i++)
        {
            dian[i].first=NULL;
        }
        struct bian *p,*e;
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);
            e=(struct bian *)malloc(sizeof(struct bian));
            e->data=v;
            e->next=NULL;
            if(dian[u].first==NULL)
            {
                e->next=dian[u].first;
                dian[u].first=e;
            }
            else
            {
                if(v<dian[u].first->data)
                {
                    e->next=dian[u].first;
                    dian[u].first=e;
                }
                else
                {
                    p=dian[u].first;
                    while(p->next->data<v&&p->next!=NULL)
                    {
                        p=p->next;
                    }
                    if(p->next==NULL)
                    {
                        p->next=e;
                        e->next=NULL;
                    }
                    else if(p->next->data>v)
                    {
                        e->next=p->next;
                        p->next=e;
                    }
                }
            }
            e=(struct bian *)malloc(sizeof(struct bian));
            e->data=u;
            e->next=NULL;
            if(dian[v].first==NULL)
            {
                e->next=dian[v].first;
                dian[v].first=e;
            }
            else
            {
                if(u<dian[v].first->data)
                {
                    e->next=dian[v].first;
                    dian[v].first=e;
                }
                else
                {
                    p=dian[v].first;
                    while(p->next->data<u&&p->next!=NULL)
                    {
                        p=p->next;
                    }
                    if(p->next==NULL)
                    {
                        p->next=e;
                        e->next=NULL;
                    }
                    else if(p->next->data>u)
                    {
                        e->next=p->next;
                        p->next=e;
                    }
                }
            }
        }
        memset(vis,0,sizeof(vis));
        queue<int>q;
        q.push(t);
        vis[t]=1;
        printf("%d ",t);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            p=dian[x].first;
            while(p)
            {
                if(vis[p->data]==0)
                {
                    vis[p->data]=1;
                    printf("%d ",p->data);
                    q.push(p->data);
                }
                p=p->next;
            }
        }
    }
}
