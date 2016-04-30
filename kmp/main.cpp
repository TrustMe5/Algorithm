#include<iostream>
#include<string.h>
using namespace std;
char s1[1000100],s2[1000100];
int next[1100010];
int getnext()
{
    int i=0,j=-1;
    next[0]=-1;
    int len=strlen(s2);
    while(i<len)
    {
        if(j==-1||s2[i]==s2[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];
    }
    return 0;
}
int output()
{
    int i=0,j=0;
    int len1=strlen(s1);
    int len2=strlen(s2);
    while(i<len1&&j<len2)
    {
        if(j==-1||s1[i]==s2[j])
        {
            i++;
            j++;
        }
        else  j=next[j];
    }
    if(j>=len2)
    {
        cout<<i-j+1<<endl;
    }
    else cout<<"::>_<::"<<endl;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s1>>s2;
        getnext();
        output();
    }
    return 0;
}
