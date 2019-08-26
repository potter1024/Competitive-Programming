queue<ll> q;
q.push(1);
visited[1]=1;                   // the vertex will be visited when it is pushed into the queue
rank[1]=0;
while(!q.empty())
{
    ll x=q.front();
    q.pop();
    for(ll i=0;i<adj[x].size();i++)
    {
        if(visited[adj[x][i]])
            continue;
        rank[adj[x][i]]=rank[x]+1;
        q.push(adj[x][i]);
        visited[adj[x][i]]=1;
    }
}
