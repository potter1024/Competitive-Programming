vi dist(n, vl); dist[s] = 0;
priority_queue< pi, vector<pi>, greater<pi> > pq; pq.push(pi(0, s));
while (!pq.empty())
{
    pi front = pq.top();
    pq.pop();
    ll d = front.first, u = front.second;
    if (d > dist[u])
        continue;
    for (int j = 0; j < (int)adj[u].size(); j++)
    {
        pi v = adj[u][j];
        if (dist[u] + v.second < dist[v.first])
        {
            dist[v.first] = dist[u] + v.second;
            pq.push(pi(dist[v.first], v.first));
        }
    }
}
