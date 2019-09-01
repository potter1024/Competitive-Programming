vector<ll> v(N,0),tree(N,0);
void build(ll node, ll start, ll end)          // initial call is build(1,0,n-1)
{                                              // node is the index of that node in segment tree (starts with 1)
    if(start == end)                           // start and end are are the range that this node in segment tree covers
    {
        tree[node] = v[start];
    }
    else
    {
        ll mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
ll query(ll node, ll start, ll end, ll l, ll r)
{
    if(r < start || end < l)
    {
        return 0;
    }
    if(l <= start && r >= end)
    {
        return tree[node];
    }
    ll mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}
void update(ll node, ll start, ll end, ll idx, ll val)
{
    if(start == end)
    {
        v[idx] += val;
        tree[node] += val;
    }
    else
    {
        ll mid = (start + end) / 2;
        if(start <= idx && idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}






//https://codeforces.com/blog/entry/15729
//https://codeforces.com/blog/entry/15890
