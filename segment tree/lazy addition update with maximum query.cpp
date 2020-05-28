void push(ll node) {
    tree[node*2] += lazy[node];
    lazy[node*2] += lazy[node];
    tree[node*2+1] += lazy[node];
    lazy[node*2+1] += lazy[node];
    lazy[node] = 0;
}
void update(ll node,ll left,ll right,ll l,ll r,ll add) {
    if(r < left || right < l){
        return;
    }
    push(node);
    if(l <= left && r >= right){
        tree[node]+=add;
        lazy[node]+=add;
    }
    else {
        ll mid = (left + right) / 2;
        update(2*node,left,mid,l,r,add);
        update(2*node+1,mid+1,right,l,r,add);
        tree[node]=max(tree[node*2],tree[node*2+1]);
    }
}

ll query(ll node,ll left,ll right,ll l,ll r){
    if(l>r){
        return -inf;
    }
    push(node);
    if(l>right || r<left){
        return -inf;
    }
    if(left>=l && right<=r){
        return tree[node];
    }
    ll mid=(left+right)/2;
    return max(query(node*2,left,mid,l,r),query(node*2+1,mid+1,right,l,r));
}
