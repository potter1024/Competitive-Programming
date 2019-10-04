// the number of edges should be equal to number of vertices

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define sz(a)               int((a).size())
#define ll                  long long
#define pb                  push_back
#define ld                  long double
#define mp                  make_pair
#define vi                  vector<ll>
#define vii                  vector<pi>
#define endl                "\n"
#define ff                  first
#define ss                  second
#define all(c)              (c).begin(),(c).end()
#define allr(c)             (c).rbegin(),(c).rend()
#define rep(i,n)            for(ll i=0;i<n;i++)
#define cpresent(c,x)       (find(all(c),x) != (c).end())
#define input(a,n)          for(long long i=0;i<n;i++)cin>>a[i]
#define output(a,n)         for(long long i=0;i<n;i++)cout<<a[i]<<" "
#define reset(a,n)          memset(a,n,sizeof(a))   // n can only be 0 or -1
#define vl                  LLONG_MIN
#define vm                  LLONG_MAX
#define ep                  1e-10
#define seed                13331
#define pi                  pair<ll,ll>
#define inf                 10e9
#define N                   1000000
#define minp                vector<ll>, greater<ll>
#define M                   1000000007
#define MM                  1000000009
#define pie                 3.1415926535897932384626433832795
#define eu                  2.718281828459045
#define                     she_taught_me_to_code cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);cin.tie(NULL);    clock_t startTime=clock();
#define time     cout<<(double(clock()-startTime )/(double)CLOCKS_PER_SEC)*1000<<" ms"<<endl;
#define debug(k) cout<<"\t-> "<<#k<<" = "<<k<<endl;

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
ll gcd(ll a,ll b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
ll min(ll a,ll b)
{
    if(a<b)
        return a;
    return b;
}
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
vi adj[N],vis(N,0),in_deg(N,0);
int dfs(int u) {
    if (vis[u])
        return u;
    vis[u] = true;
    for (int v : adj[u])
        return dfs(v);
    assert(false);
    return -1;
}
int main()
{
    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        in_deg[b]++;
    }
    vii segs;
    int lines = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (in_deg[i] == 0)
        {
            lines++;
            int j = dfs(i);
            segs.emplace_back(i, j);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            dfs(i);
            segs.emplace_back(i, i);
        }
    }

    int l = segs.size();
    if (l == 1 && lines == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    cout << l << '\n';
    for (int i = 0; i < l; ++i)
    {
        int j = (i + 1) % l;
        cout << (segs[i].second) << ' ' << (segs[j].first) << '\n';
    }
}
