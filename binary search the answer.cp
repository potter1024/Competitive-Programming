// if we want to maximize the result

ll start=0,end=n-1,mid=(start+end)/2;
while(start!=end)
{
    mid=(start+end)/2;
    if(check(mid)==1)
    {
        start=mid;
    }
    else
    {
        end=mid;
    }
    if(start==end-1)
    {
        if(check(end)==1)
            start=end;
        else
            end=start;
    }
}
cout<<start;



// if we want to minimize the result

ll start=0,end=n-1,mid=(start+end)/2;
while(start!=end)
{
    mid=(start+end)/2;
    if(check(mid)==1)
    {
        end=mid;
    }
    else
    {
        start=mid;
    }
    if(start==end-1)
    {
        if(check(start)==1)
            end=start;
        else
            start=end;
    }
}
cout<<end;
