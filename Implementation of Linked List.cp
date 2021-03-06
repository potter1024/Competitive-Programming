#include<iostream>
#include<cstdlib>
using namespace std;
struct node                                 //defining linked list structure
{
    int data;
    struct node *link;
};
void insert(struct node **q,int n)          //insert function
{
    struct node *temp,*r;
    temp=*q;
    if(*q==NULL)
    {
        r=(struct node*) malloc(sizeof(struct node));
        r->data=n;
        r->link=NULL;
        *q=r;
    }
    else
    {
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        r=(struct node*) malloc(sizeof(struct node));
        r->data=n;
        r->link=NULL;
        temp->link=r;
    }
}
void print(struct node **q)                 //function to print linked list
{
    struct node *temp;
    temp=*q;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}
int count(struct node **q)                  //function to count number of nodes in linked list
{
    int count=0;
    struct node *temp;
    temp=*q;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    return count;
}
int del(struct node **q,int n)              //function to delete an element
{
    struct node *temp,*old;
    temp=*q;
    old=*q;
    int i=0;
    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            if(temp==*q)
            {
                *q=temp->link;
                free(temp);
            }
            else if(temp->link==NULL)
            {
                old->link=NULL;
                free(temp);
            }
            else
            {
                old->link=temp->link;
                free(temp);
            }
        }
        if(temp!=*q)
        {
            old=old->link;
        }
        temp=temp->link;
        i=1;
    }
    if(i==1)
        return 1;
    else
        return 0;
}
void update(struct node **q,int j,int n)
{
    struct node *temp,*r;
    temp=*q;
    for(int i=0;i<j-1;i++)
    {
        temp=temp->link;
    }
    r=(struct node*)malloc(sizeof(struct node));
    r->link=temp->link;
    r->data=n;
    temp->link=r;
}
int main()
{
    using namespace std;
    int j,n;
    struct node *head;
    head=NULL;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>j;
        insert(&head,j);
    }
}
