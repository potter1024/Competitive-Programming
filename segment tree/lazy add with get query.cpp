void build(ll node, ll left, ll right){
    if(left == right){
        tree[node] = v[left];
    }
    else{
        ll mid = (left + right) / 2;
        build(2*node, left, mid);
        build(2*node+1, mid+1, right);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void update(ll node,ll left,ll right,ll l,ll r,ll add) {
    if(r < left || right < l){
        return;
    }
    if(l <= left && r >= right){
        tree[node]+=add;
    }
    else {
        ll mid = (left + right) / 2;
        update(2*node,left,mid,l,r,add);
        update(2*node+1,mid+1,right,l,r,add);
    }
}

ll get(ll node,ll left,ll right,ll pos) {
    if (left == right)
        return tree[node];
    ll mid = (left + right) / 2;
    if (pos <= mid)
        return tree[node] + get(node*2,left,mid,pos);
    else
        return tree[node] + get(node*2+1,mid+1,right,pos);
}
