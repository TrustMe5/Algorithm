#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
struct node
{
    char data;
    struct node *l,*r;
};
struct node *create(struct node *p)
{
    char c;
    cin>>c;
    if(c==',')p=NULL;
    else
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=c;
        p->l=create(p->l);
        p->r=create(p->r);
    }
    return p;
};
void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->l);
        cout<<p->data;
        inorder(p->r);
    }
}
void lastorder(struct node *p)
{
    if(p)
    {
        lastorder(p->l);
        lastorder(p->r);
        cout<<p->data;
    }
}
int num=0;
void yezi(struct node *p)
{
    if(p)
    {
        if(p->l==NULL&&p->r==NULL)
            num++;

        yezi(p->l);
        yezi(p->r);

    }
}
int deep(struct node *p)
{
    int ld=0,rd=0;
    if(p==NULL) return 0;
    else
    {
        ld=deep(p->l);
        rd=deep(p->r);
        if(ld>rd) return ld+1;
        else return rd+1;
    }
}
int main()
{
    struct node *p;
    p=create(p);
    inorder(p);
    cout<<endl;
    lastorder(p);
    cout<<endl;
    yezi(p);
    cout<<num<<endl;
    int depth=deep(p);
    cout<<depth<<endl;
    return 0;
}
