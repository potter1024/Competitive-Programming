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
ll mi=min(start,end);
ll ma=max(start,end);
(check(ma)==1)?cout<<ma:cout<<mi;



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
ll mi=min(start,end);
ll ma=max(start,end);
(check(mi)==1)?cout<<mi:cout<<ma;
