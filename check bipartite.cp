#define N 1000000
vi adj[N],color(N,0),visited(N,0);
ll DFS(ll u,ll c)
{
    color[u]=c;
    visited[u]=1;
    for(ll i=0;i<adj[u].size();i++)
    {
        if(color[adj[u][i]]==c)
        {
            return -1;
        }
        color[adj[u][i]]=-c;
    }
    for(ll i=0;i<adj[u].size();i++)
    {
        if(visited[adj[u][i]]==0)
        {
            if(DFS(adj[u][i],-c)==-1)
            {
                return -1;
            }
        }
    }
    return 0;
}
void aE(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
