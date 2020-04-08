ll id[N]={};
ll sz[N]={};
void initialise(ll n){
    for(ll i=1;i<=n;i++){
        id[i]=i;
        sz[i]=1;
    }
}
ll root(ll i){
    if(id[i]==i){
        return i;
    }
    return id[i]=root(id[i]);
}
bool connected(ll a,ll b){
    return root(a)==root(b);
}
void merge(ll a,ll b)
{
    ll i=root(a),j=root(b);
    if(i==j){
        return;
    }
    if(sz[i]<sz[j]){
        id[i]=j;
        sz[j]+=sz[i];
    }
    else{
        id[j]=i;
        sz[i]+=sz[j];
    }
}
