/*************************************************************************
	> File Name: code.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 21时02分03秒
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
int len,n,large;
int heapify(int a[],int i)
{
    if(2*i<=len&&a[2*i]>a[i])
    {
        large=2*i;
    }
    else large=i;
    if(2*i+1<=len&&a[2*i+1]>a[large])
    {
        large=2*i+1;
    }
    if(large!=i)
    {
        swap(a[i],a[large]);
        heapify(a,large);
    }
    return 0;
}
int build(int a[])
{
    int i;
    for(i=n/2;i>=1;i--)
    {
        heapify(a,i);
    }

}
int heapsort(int a[])
{
    int i;
    build(a);
    for(i=n;i>=2;i--)
    {
        swap(a[i],a[1]);
        len--;
        heapify(a,1);
    }
}
int main()
{
    int a[110];
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    len=n;
    heapsort(a);
    for(i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
