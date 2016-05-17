/*************************************************************************
	> File Name: code.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月30日 星期六 22时25分45秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int i,j,n,num;
    vector<int>v;
    cin>>n;
    v.push_back(1);
    v.push_back(2);
    for(i=2;i<n;i++)
    {
        int tt=v[i-2]+v[i-1];
        v.push_back(tt);
    }
    cout<<v[47]<<endl;

    return 0;
}
