#define MAX 1000000
ll id[MAX]={};
ll sz[MAX]={};
void run(ll n)
{
    for(ll i=1;i<=n;i++)
    {
        id[i]=i;
        sz[i]=1;
    }
}
ll root(ll i)
{
    while(id[i]!=i)
    {
        id[i]=id[id[i]];
        i=id[i];
    }
    return i;
}
bool connected(ll a,ll b)
{
    return root(a)==root(b);
}
void add(ll a,ll b)
{
    ll i=root(a),j=root(b);
    if(i==j)
    return;
    if(sz[i]<sz[j])
    {
        id[i]=j;
        sz[j]+=sz[i];
    }
    else
    {
        id[j]=i;
        sz[i]+=sz[j];
    }
}
