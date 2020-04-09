vector<ll> v(N,0);
vector<vector<ll>> tree(4*N);
ll n;
void build(ll node,ll left,ll right){
    if(left==right){
        tree[node].pb(v[left]);
        return;
    }
    ll mid=(left+right)/2;
    build(node*2,left,mid);
    build(node*2+1,mid+1,right);
    tree[node].resize(right-left+1);
    merge(all(tree[node*2]),all(tree[node*2+1]),tree[node].begin());
}
ll query(ll node,ll left,ll right,ll l,ll r,ll x){
    if(l<=left && r>=right){
        auto it=upper_bound(all(tree[node]),x);
        if(it!=tree[node].end()){
            return *it;
        }
        return INT_MAX;
    }
    if(l>right || r<left){
        return INT_MAX;
    }
    ll mid=(left+right)/2;
    ll num1=query(node*2,left,mid,l,r,x);
    ll num2=query(node*2+1,mid+1,right,l,r,x);
    return min(num1,num2);
}
