/*************************************************************************
	> File Name: code.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年05月17日 星期二 18时17分52秒
 ************************************************************************/

#include<iostream>
using namespace std;
int a[110],b[110];
int count=0;
void merge(int a[],int begin,int mid,int end)
{
    int i=begin,j=mid+1,k=0;
    while(i<=mid&&j<=end)
    {
        if(a[i]<a[j])
        b[k++]=a[i++];
        else
        {
        b[k++]=a[j++];
        count+=mid-i+1;
     }
    }
    while(i<=mid)
    b[k++]=a[i++];
    while(j<=end)
    b[k++]=a[j++];
    for(i=0;i<k;i++)
    {
        a[begin+i]=b[i];
    }
}
void mergesort(int a[],int begin,int end)
{
    if(begin<end)
    {
        int mid=(begin+end)/2;
        mergesort(a,begin,mid);
        mergesort(a,mid+1,end);
        merge(a,begin,mid,end);
    }
}
int main()
{
    int i,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<count<<endl;
    return 0;
}
