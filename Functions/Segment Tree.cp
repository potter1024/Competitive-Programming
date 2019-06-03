vector<ll> v(N,0);
vector<ll> segTree(N,0);
void build(ll low,ll high,ll pos)           // initial call is build(0,n-1,1);
{
    if(low==high)
    {
        segTree[pos]=v[low];
        return;
    }
    ll mid=(low+high)/2;
    build(low,mid,pos*2);
    build(mid+1,high,pos*2+1);
    segTree[pos]=segTree[pos*2]+segTree[pos*2+1];                       // should be modified
}
ll querry(ll low,ll high,ll l,ll r,ll pos)              // l and r start from 0
{
    if(l<=low && r>=high)
        return segTree[pos];
    else if(r<low || l>high)
        return 0;                                                       // should be modified
    ll mid=(low+high)/2;
    return querry(low,mid,l,r,2*pos)+querry(mid+1,high,l,r,2*pos+1);    // should be modified
}
void update(ll low,ll high,ll index,ll val,ll pos)      // l and r start from 0
{
    if(low==high)
    {
        v[index]=val;
        segTree[pos]=val;
    }
    else
    {
        ll mid =(low+high)/2;
        if(low<=index && index<=mid)
            update(low,mid,index,val,2*pos);
        else
            update(mid+1,high,index,val,2*pos+1);
        segTree[pos]=segTree[2*pos]+segTree[2*pos+1];                    // should be modified
    }
}
