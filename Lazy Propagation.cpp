vector<ll> v(N),lazy(4*N),tree(4*N);
void build(ll node, ll start, ll end){
    if(start == end){
        tree[node] = v[start];
    }
    else{
        ll mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void updateRange(ll node, ll start, ll end, ll l, ll r, ll val){
    if(lazy[node] != 0){
        tree[node] += (end - start + 1) * lazy[node];    
        if(start != end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end or start > r or end < l)
        return;
    if(start >= l and end <= r){
        tree[node] += (end - start + 1) * val;
        if(start != end){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    ll mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(ll node, ll start, ll end, ll l, ll r){
    if(start > end or start > r or end < l)
        return 0;
    if(lazy[node] != 0){
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l and end <= r)
        return tree[node];
    ll mid = (start + end) / 2;
    ll sum1 = query(node*2, start, mid, l, r);
    ll sum2 = query(node*2 + 1, mid + 1, end, l, r);
    return (sum1 + sum2);
}
