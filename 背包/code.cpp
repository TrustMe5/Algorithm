/*************************************************************************
	> File Name: code.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月21日 星期四 12时42分33秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
int main()
{
    int n,i,j,a[11000],dp[10010],sum;
    while(cin>>n)
    {
        memset(dp,0,sizeof(dp));
        sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int tt=sum/2;
    for(i=0;i<n;i++)
    {
        for(j=tt;j>=0;j--)
        {
            if(j>=a[i])
            {
                dp[j]=max(dp[j],(dp[j-a[i]]+a[i]));
            }
        }
    }
    if(n==1)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        sum=abs(sum-2*dp[tt]);
        cout<<sum<<endl;
    }
    }
    return 0;
}
