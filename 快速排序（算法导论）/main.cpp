#include <iostream>

using namespace std;
int a[100010];
int parti(int a[],int low,int high)
{
    int i=low-1,j=low;
    while(j<high)
    {
        if(a[j]>a[high])        //和a[high]比较，大于a[high]的数放在右边，小于a[high]的放在左边
            j++;
        else
        {
            i++;
            swap(a[i],a[j]);
            j++;
        }
    }
    i++;
    swap(a[i],a[high]);
    return i;
}
void qksort(int a[],int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot=parti(a,low,high);
        qksort(a,low,pivot-1);
        qksort(a,pivot+1,high);
    }
}
int main()
{
    int i,n;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    qksort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        if(i==n-1)
            cout<<a[i]<<endl;
        else cout<<a[i]<<" ";
    }
    return 0;
}
