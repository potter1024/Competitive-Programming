// if we want to maximize the result

ll start=0,end=n-1,mid=(start+end)/2;
while(start<=end)
{
    mid=(start+end)/2;
    if(check(mid)==1)
    {
        start=mid+1;
    }
    else
    {
        end=mid-1;
    }
}
cout<<start;



// if we want to minimize the result

ll start=0,end=n-1,mid=(start+end)/2;
while(start<=end)
{
    mid=(start+end)/2;
    if(check(mid)==1)
    {
        end=mid-1;
    }
    else
    {
        start=mid+1;
    }
}
cout<<end;
