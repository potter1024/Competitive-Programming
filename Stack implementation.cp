#include<iostream>
void push(int *a,int n,int *e)
{
    *(a+*e+1)=n;
    (*e)++;
}
void pop(int *a,int *e)
{
    using namespace std;
    if(*e==-1)
    {
        cout<<"Stack underflow"<<endl;
    }
    else
    {
        cout<<"The popped number is "<<*(a+*e)<<endl;
        (*e)--;
    }
}
int main()
{
    using namespace std;
    int i,n,a[100],e=-1;
    while(1)
    {
        cout<<"Enter 1 to PUSH and 2 to POP"<<endl;
        cin>>i;
        if(i==1)
        {
            if(e>98)
            {
                cout<<"Stack overflow"<<endl;
            }
            else
            {
                cout<<"Enter the number to push"<<endl;
                cin>>n;
                push(a,n,&e);
            }
            cout<<"The stack is as follows"<<endl;
            cout<<"_"<<endl;
            for(int i=e;i>=0;i--)
            {
                cout<<a[i]<<endl;
            }
            cout<<"-"<<endl<<endl;
        }
        else if(i==2)
        {
            pop(a,&e);
            if(e!=-1)
            {
                cout<<"The stack is as follows"<<endl;
                cout<<"_"<<endl;
                for(int i=e;i>=0;i--)
                {
                    cout<<a[i]<<endl;
                }
                cout<<"-"<<endl<<endl;
            }
            else
                cout<<"No stack to show"<<endl;
        }
        else
            cout<<"Invalid input"<<endl;
    }
}
