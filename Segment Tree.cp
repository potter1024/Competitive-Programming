vector<ll> v(N,0),tree(N,0);
void build(ll node, ll left, ll right){         // initial call is build(1,0,n-1)
    if(left == right){
        tree[node] = v[start];
    }
    else{
        ll mid = (left + right) / 2;
        build(2*node, left, mid);
        build(2*node+1, mid+1, right);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
ll query(ll node, ll left, ll right, ll l, ll r){
    if(r < left || right < l){
        return 0;
    }
    if(l <= left && r >= right){
        return tree[node];
    }
    ll mid = (left + right) / 2;
    ll p1 = query(2*node, left, mid, l, r);
    ll p2 = query(2*node+1, mid+1, right, l, r);
    return (p1 + p2);
}
void update(ll node, ll left, ll right, ll idx, ll val){
    if(left == right){
        v[idx] += val;
        tree[node] += val;
    }
    else{
        ll mid = (left + right) / 2;
        if(left <= idx && idx <= mid){
            update(2*node, left, mid, idx, val);
        }
        else{
            update(2*node+1, mid+1, right, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}






//https://codeforces.com/blog/entry/15729
//https://codeforces.com/blog/entry/15890
