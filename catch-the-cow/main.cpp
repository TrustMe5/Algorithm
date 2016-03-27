#include <iostream>
#include<string.h>
#include <queue>
using namespace std;
int step[100010],vis[100010];
int n,k;
void bfs(int n)
{
  int i,s;
  queue<int>q;
  memset(vis,0,sizeof(vis));
  while(!q.empty())
  {
      q.pop();
  }
q.push(n);
vis[n]=1;
while(!q.empty())
{
    int x=q.front();
    q.pop();
    if(x==k)
    {
        cout<<step[x]<<endl;
        return;
    }
    for(i=0;i<3;i++)
    {
        if(i==0)
        {
            s=x+1;
        }
        else if(i==1)
        {
            s=x-1;
        }
        else s=2*x;
        if(!vis[s]&&s>=0&&s<100010)
        {
            vis[s]=1;
            step[s]=step[x]+1;
            q.push(s);
        }
    }
}
}
int main()
{
    while(cin>>n>>k)
    {
      if(n>=k)
      {
       cout<<n-k<<endl;
      }
      else
      {
          bfs(n);
      }
    }
    //cout << "Hello world!" << endl;
    return 0;
}
