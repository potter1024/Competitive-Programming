void push(ll node) {
    if (marked[node]) {
        tree[node*2] = tree[node*2+1] = tree[node];
        marked[node*2] = marked[node*2+1] = 1;
        marked[node] = 0;
    }
}
void update(ll node,ll left,ll right,ll l,ll r,ll new_val){
    if(r < left || right < l){
        return;
    }
    if(l <= left && r >= right){
        tree[node]=new_val;
        marked[node]=1;
    }
    else{
        push(node);
        ll mid=(left+right)/2;
        update(node*2,left,mid,l,r,new_val);
        update(node*2+1,mid+1,right,l,r,new_val);
    }
}
ll get(ll node,ll left,ll right,ll pos){
    if(left==right){
        return tree[node];
    }
    push(node);
    ll mid=(left+right)/2;
    if(pos<=mid){
        return get(node*2,left,mid,pos);
    }
    else{
        return get(node*2+1,mid+1,right,pos);
    }
}
