//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <cmath>
#include<math.h>
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
#define sz(a) int((a).size())
#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define vi vector<ll>
#define endl "\n"
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define rep(i,n) for(ll i=0;i<n;i++)
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define input(a,n) for(long long i=0;i<n;i++)cin>>a[i]
#define output(a,n) for(long long i=0;i<n;i++)cout<<a[i]<<" "
#define     she_taught_me_to_code cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ep 1e-10
#define pi pair<ll,ll>
#define inf 10e9
#define N 1000000
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
ll gcd(ll a,ll b,ll count)
{
    if (b == 0)
        return count+1;
    return gcd(b, a - b,count+1);
}
/*ll lcm1(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}*/
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
    return b;}
#define M 1000000007
#define N 1000000
vector<ll> adj[N];
vector<bool> visited(N,0);
void DFSUtil(ll u)
{
    visited[u] = true;
    for (ll i=0; i<adj[u].size(); i++)
    {
        if (visited[adj[u][i]] == false)
        {
            DFSUtil(adj[u][i]);
        }
    }
}
void DFS(ll n)
{
    for (ll u=0; u<n; u++)
    {
        if (visited[u] == false)
        {
            DFSUtil(u);
        }
    }
}
void aE(ll u, ll v)
{
    adj[u].push_back(v);
}
int main()
{
    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ll a,b,count=0;
    cin>>a>>b;
    while(1)
    {
        count++;
        if(a>b)
        {
            a += b;
        }
        else if(a<b)
        {
            b -= a;
        }
        else
        {
            break;
        }
    }
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            count += a / b;
            a %= b;
        }
        else
        {
            count += b / a;
            b %= a;
        }
    }
    cout<<count;
}
