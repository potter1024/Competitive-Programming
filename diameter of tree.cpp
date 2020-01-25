    ll n;
    cin>>n;
    for(ll i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    queue<ll> q1;
    q1.push(1);
    vector<ll> dist(N,0),vis(N,0);
    vis[1]=1;
    ll end,ma=0;
    while(!q1.empty())
    {
        ll x=q1.front();
        q1.pop();
        for(ll i=0;i<adj[x].size();i++)
        {
            if(!vis[adj[x][i]])
            {
                q1.push(adj[x][i]);
                vis[adj[x][i]]=1;
                dist[adj[x][i]]=dist[x]+1;
                if(dist[adj[x][i]]>ma)
                {
                    ma=dist[adj[x][i]];
                    end=adj[x][i];
                }
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        vis[i]=0;
        dist[i]=0;
    }
    q1.push(end);
    vis[end]=1;
    ma=0;
    while(!q1.empty())
    {
        ll x=q1.front();
        q1.pop();
        for(ll i=0;i<adj[x].size();i++)
        {
            if(!vis[adj[x][i]])
            {
                q1.push(adj[x][i]);
                vis[adj[x][i]]=1;
                dist[adj[x][i]]=dist[x]+1;
                if(dist[adj[x][i]]>ma)
                {
                    ma=dist[adj[x][i]];
                    end=adj[x][i];
                }
            }
        }
    }
    vector<ll> diam;
    diam.pb(end);
    ll u=end,d=dist[end];
    while(d)
    {
        for(ll i=0;i<adj[u].size();i++)
        {
            if(dist[adj[u][i]]==d-1)
            {
                diam.pb(adj[u][i]);
                d--;
                u=adj[u][i];
                break;
            }
        }
    }
    
    // diam will store the path of diameter
