#define MAX 100005
ll n;
ll v[20][MAX],tree[20][4*MAX];
bool lazy[20][4*MAX];
void build(ll node,ll left,ll right,ll index){
    if(left==right){
        tree[index][node]=v[index][left];
        return;
    }
    ll mid=(left+right)/2;
    build(node*2,left,mid,index);
    build(node*2+1,mid+1,right,index);
    tree[index][node]=tree[index][node*2]+tree[index][node*2+1];
}
void push(ll node,ll left,ll right,ll index){
    tree[index][node]=right-left+1-tree[index][node];
    if(left!=right){
        lazy[index][node*2]^=1;
        lazy[index][node*2+1]^=1;
    }
    lazy[index][node]=0;
}
void update(ll node,ll left,ll right,ll l,ll r,ll index){
    if(lazy[index][node]){
        push(node,left,right,index);
    }
    if(r<left || l>right){
        return;
    }
    if(l<=left && r>=right){
        lazy[index][node]=1;
        push(node,left,right,index);
        return;
    }
    ll mid=(left+right)/2;
    update(node*2,left,mid,l,r,index);
    update(node*2+1,mid+1,right,l,r,index);
    tree[index][node]=tree[index][node*2]+tree[index][node*2+1];
}
ll query(ll node,ll left,ll right,ll l,ll r,ll index){
    if(r<left || l>right){
        return 0;
    }
    if(lazy[index][node]){
        push(node,left,right,index);
    }
    if(l<=left && r>=right){
        return tree[index][node];
    }
    ll mid=(left+right)/2;
    return query(node*2,left,mid,l,r,index)+query(node*2+1,mid+1,right,l,r,index);
}
