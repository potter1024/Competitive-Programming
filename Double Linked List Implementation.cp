#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
void insert(struct node **q,int n)
{
    struct node *temp,*r;
    temp=*q;
    r=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        r->prev=NULL;
        r->data=n;
        r->next=NULL;
        *q=r;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=r;
        r->prev=temp;
        r->data=n;
        r->next=NULL;

    }
}
int count(struct node **q)
{
    struct node *temp;
    int count=0;
    temp=*q;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
void print(struct node **q)
{
    struct node *temp;
    temp=*q;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void update(struct node **q,int j,int n)
{
    struct node *temp,*r,*t;
    temp=*q;
    r=(struct node *)malloc(sizeof(struct node));
    if(j==0)
    {
        *q=r;
        temp->prev=r;
        r->prev=NULL;
        r->data=n;
        r->next=temp;
    }
    else if(j==count(q))
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=r;
        r->prev=temp;
        r->data=n;
        r->next=NULL;
    }
    else
    {
        for(int i=0;i<j-1;i++)
        {
            temp=temp->next;
        }
        t=temp->next;
        temp->next=r;
        r->prev=temp;
        r->data=n;
        r->next=t;
        t->prev=r;
    }
}
int del(struct node **q,int n)
{
    struct node *temp;
    temp=*q;
    while((temp->next)->data!=n)
    {
        temp=temp->next;
    }
    if(((temp->next)->next)==NULL)
    {
        return 0;
    }

    ((temp->next)->next)->prev=temp;
    temp->next=(temp->next)->next;
    free(temp->next);
    return 1;
}
int main()
{
    int n,data;
    struct node *head;
    head=NULL;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insert(&head,data);
    }
    del(&head,3);
    print(&head);
}
