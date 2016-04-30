#include <iostream>
#include<string.h>
using namespace std;

int main()
{
    int i,j,len=1,last;
    int map[110][110];
    string s1,s2;
    cin>>s1>>s2;
    int len1=s1.length();
    int len2=s2.length();
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            if(i==0||j==0)
            {
                if(s1[i]==s2[j])
                    map[i][j]=1;
                    else map[i][j]=0;
            }
            else
            {
                if(s1[i]==s2[j])
                {
                    map[i][j]=map[i-1][j-1]+1;
                    if(len<map[i][j])
                    {
                        len=map[i][j];
                        last=i;
                    }
                }
            }
        }
    }
    cout<<"len: "<<len<<endl;
    cout<<"last: "<<last<<endl;
    for(i=last-len+1;i<=last;i++)
    {
        cout<<s1[i];
    }
    cout<<endl;
//    cout << "Hello world!" << endl;
    return 0;
}
