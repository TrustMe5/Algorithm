#include<string.h>
#include<stdio.h>
int main()
{
    int n,i,m,a[100020];
    int mid,low,high;
    while(~scanf("%d",&n))
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        low=0;
        high=n;
        mid=(low+mid)/2;
       while(low<=high)
        {
            if(a[mid]<m)
            {
                low=mid+1;
            }
            else if(a[mid]>m) high=mid-1;
            else break;
            mid=(low+high)/2;
        }
        if(low<=high) printf("YES\n");
        else  printf("NO\n");
    }
    return 0;
}
