ll n,timer=0;
vi adj[N],v(N,0),st(N),en(N),euler,tree(N),lazy(N);
void dfs(ll u,ll p){
    timer++;
    st[u]=timer;
    euler.pb(u);
    for(ll i=0;i<adj[u].size();i++){
        if(adj[u][i]!=p){
            dfs(adj[u][i],u);
        }
    }
    en[u]=timer;
}
void push(ll node,ll left,ll right){
    if(left!=right){
        lazy[node*2]^=1;
        lazy[node*2+1]^=1;
    }
    tree[node]=(right-left+1)-tree[node];
    lazy[node]=0;
}
void build(ll node,ll left,ll right){
    if(left==right){
        tree[node]=v[left];
        return;
    }
    ll mid=(left+right)/2;
    build(node*2,left,mid);
    build(node*2+1,mid+1,right);
    tree[node]=tree[node*2]+tree[node*2+1];
}
void update(ll node,ll left,ll right,ll l,ll r){
    if(lazy[node]){
        push(node,left,right);
    }
    if(r<left || l>right){
        return;
    }
    if(l<=left && r>=right){
        lazy[node]=1;
        push(node,left,right);
        return;
    }
    ll mid=(left+right)/2;
    update(node*2,left,mid,l,r);
    update(node*2+1,mid+1,right,l,r);
    tree[node]=tree[node*2]+tree[node*2+1];
}
ll query(ll node,ll left,ll right,ll l,ll r){
    if(r<left || l>right){
        return 0;
    }
    if(lazy[node]){
        push(node,left,right);
    }
    if(l<=left && r>=right){
        return tree[node];
    }
    ll mid=(left+right)/2;
    return query(node*2,left,mid,l,r)+query(node*2+1,mid+1,right,l,r);
}



// Each vertex contain a bit, 0 or 1
// This is the code for query as number of ones in a subtree and update of inverting all numbers in subtree of a vertex







// to be called from main

for(ll i=1;i<=n;i++){
    cin>>temp[i];
}
dfs(1,0);
for(ll i=1;i<=n;i++){
    v[i]=temp[euler[i-1]];
}
build(1,1,n);
query(1,1,n,st[x],en[x]);
update(1,1,n,st[x],en[x]);
