#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct node
{
    int num;
    struct node *next;
};
int main()
{
    int M,i,j;
    struct node *head,*tail,*p,*q;
    while(cin>>M&&M)
    {
        head=(struct node *)malloc(sizeof(struct node));
        head->next=NULL;
        tail=head;
        for(i=1; i<=M; i++)
        {
            p=(struct node *)malloc(sizeof(struct node));
            p->num=i;
            p->next=NULL;
            tail->next=p;
            tail=p;
        }
        tail->next=head->next;
        int sum=1;
        for(i=1,p=head;;i++)
        {
            if(i%5==0&&p->next->num==1)
            {
                cout<<sum<<endl;
                break;
            }
            else if (i%5==0)
            {
                q=p->next;
                p->next=q->next;
                free(q);
                sum++;
            }
            else p=p->next;
        }
    }
    return 0;
}
