vector<ll> v(N,0);
vector<multiset<ll>> tree(4*N);
ll n;
void build(ll node,ll left,ll right){
    if(left==right){
        tree[node].insert(v[left]);
        return;
    }
    ll mid=(left+right)/2;
    build(node*2,left,mid);
    build(node*2+1,mid+1,right);
    tree[node].insert(all(tree[node*2]));
    tree[node].insert(all(tree[node*2+1]));
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
void update(ll node,ll left,ll right,ll index,ll x){
    tree[node].erase(tree[node].find(v[index]));
    tree[node].insert(x);
    if(left==right){
        v[index]=x;
        return;
    }
    ll mid=(left+right)/2;
    if(index>=left && index<=mid){
        update(node*2,left,mid,index,x);
    }
    else{
        update(node*2+1,mid+1,right,index,x);
    }
}
