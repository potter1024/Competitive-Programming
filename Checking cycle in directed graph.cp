//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <math.h>
#include <set>
#include <time.h>
#include <map>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <numeric>
#include <unordered_map>
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

/************************************Debugging Steps*****************************************/

// If aplying ceil,floor,pow,etc convert it into integer (might make you eat shit if you don't
// Whenever using stacks,queues,etc always check that their top / front / back elements are not accessed when they are empty, thus causing runtime error
// Think twice before using greedy
// Remember losing 1 or 2 minutes is better than a penalty of 10 minutes
// Use log2 instead of log()/log(2) to avoid shitty errors
// If declaring a large array, define it globally
// Always initialise anything while declaring, which will not be taken as input
// In case of a problem having decimal calculations, try declaring everything in double rather than typecasting in each step
// always declare the array with n+5 elements to avoid unexpected errors
// Every problem cannot be solved by DFS easily, think of BFS too
/********************************************************************************************/

/********************************************************************************************/

// Your code need to originate from the deepest of your intellectual mind
// Best of Luck, may there never be "Wrong answer on test ##"

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
ll gcd(ll a,ll b)
{
    return b?gcd(b, a % b):a;
}
ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}
vi visiting(N,0),visited(N,0),adj[N];
bool dfs(ll u)
{
    visiting[u]=1;
    for(ll i=0;i<adj[u].size();i++)
    {
        if(visiting[adj[u][i]])                             // any vertex is found whose dfs is still in the process then there exists a cycle
            return 1;
        if(!visited[adj[u][i]] && dfs(adj[u][i]))
            return 1;
    }
    visiting[u]=0;
    visited[u]=1;
    return 0;
}
int32_t main()
{
    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("input.txt","w",stdout);

    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    bool cycle=0;
    for(ll i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            cycle |= dfs(i);
        }
        if(cycle)
            break;
    }
    cout<<cycle<<endl;
}
