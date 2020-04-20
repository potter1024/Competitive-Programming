ll num_sho_path(ll u,ll v){ // calculate number of shortest paths between u and v
    vi dist(n+1,inf),dp(n+1,0);
    vii vec;
    queue<ll> q;
    q.push(u);
    dist[u]=0;
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        for(ll i=0;i<adj[x].size();i++){
            if(dist[adj[x][i]]==inf){
                dist[adj[x][i]]=dist[x]+1;
                q.push(adj[x][i]);
            }
        }
    }
    for(ll i=1;i<=n;i++){
        vec.pb({dist[i],i});
    }
    sort(all(vec));
    dp[u]=1;
    for(ll i=0;i<vec.size();i++){
        for(ll j=0;j<adj[vec[i].ss].size();j++){
            if(dist[adj[vec[i].ss][j]]==dist[vec[i].ss]-1){
                dp[vec[i].ss]+=dp[adj[vec[i].ss][j]];
            }
        }
    }
    return dp[v];
}
