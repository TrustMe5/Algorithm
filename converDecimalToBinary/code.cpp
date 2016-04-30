/*************************************************************************
	> File Name: code.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月30日 星期六 22时04分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    long long  num,a[110];
    int i=0,j;
    cin>>num;
    while(num>0)
    {
        a[i++]=num%2;
        num=num/2;
    }
    for(j=i-1;j>=0;j--)
    {
        cout<<a[j];
    }


    return 0;
}
