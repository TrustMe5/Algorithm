/*************************************************************************
	> File Name: code.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月30日 星期三 20时50分10秒
 ************************************************************************/

#include<iostream>

using namespace std;
int f[100010],m,n;
int find(int x)
{
if(f[x]==x) return x;
    else
    {
        return f[x]=find(f[x]);
    }
}
void hebing(int x,int y)
{
    int i;
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    {
        for(i=0;i<m;i++)
        {
            if(f[i]==fy)
            {
                f[i]=fx;
            }
        }
    }
}
int main()
{
    int a,b,c,i,j;
    while(cin>>m>>n&&(m+n))
    {
        int sum=0;
        for(i=0;i<m;i++)
        {
            f[i]=i;
        }
        while(n--)
        {
            cin>>a;
            cin>>b;
            a--;
            for(j=0;j<a;j++)
            {
                cin>>c;
                hebing(b,c);
            }
        }
        for(i=0;i<m;i++)
        {
            if(f[i]==f[0])
            {
                sum++;
            }
        }
        cout<<sum<<endl;
    }
}
