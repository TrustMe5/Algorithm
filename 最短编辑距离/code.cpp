/*************************************************************************
	> File Name: code.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年05月07日 星期六 20时30分39秒
 ************************************************************************/

#include<iostream>
using namespace std;
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}
int edit(string s1,string s2)
{
    int i,j,d,temp;
    int len1=s1.length();
    int len2=s2.length();
    int map[110][110];
    for(i=0;i<len1+1;i++)
    {
        map[i][0]=i;
    }
    for(i=0;i<len2+1;i++)
    {
        map[0][i]=i;
    }
    for(i=1;i<len1+1;i++)
    {
        for(j=1;j<len2+1;j++)
        {
            temp=min(map[i-1][j]+1,map[i][j-1]+1);
            if(s1[i-1]==s2[j-1])
            {
                d=0;
            }
            else d=1;
            map[i][j]=min(temp,map[i-1][j-1]+d);
        }
    }
    cout<<"********************"<<endl;
    for(i=0;i<len1+1;i++)
    {
        for(j=0;j<len2+1;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"********************"<<endl;
    return map[len1][len2];
}
int main()
{
    int len1,len2,i,j;
    string s1,s2;
    cin>>s1>>s2;
    int r=edit(s1,s2);
    cout<<"最短编辑距离为："<<r<<endl;


    return 0;
}
