#include <iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int m,i,n,a[100010],num;
    cin>>m>>n;
    for(i=0;i<m;i++)
    {
        cin>>num;
        a[num]=1;
    }
    for(i=0;i<n;i++)
    {
        cin>>num;
        if(a[num]==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
   // cout << "Hello world!" << endl;
    return 0;
}
