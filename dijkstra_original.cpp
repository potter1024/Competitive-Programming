priority_queue<pi,vector<pi>, greater<pi>> pq;
vi dist(N,inf),visited(N,0),par(N);
dist[1]=0;
pq.push({0,1});
while(!pq.empty()){
    pi p=pq.top();
    pq.pop();
    ll v=p.ss;
    ll d=p.ff;
    if(visited[v]){
        continue;
    }
    visited[v]=1;
    for(ll i=0;i<adj[v].size();i++){
        if(dist[adj[v][i].ss]>d+adj[v][i].ff){
            dist[adj[v][i].ss]=d+adj[v][i].ff;
            pq.push({dist[adj[v][i].ss],adj[v][i].ss});
            par[adj[v][i].ss]=v;
        }
    }
}
