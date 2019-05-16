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
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define For(i,n) for(ll i=0;i<n;i++)
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define input(a,n) for(long long i=0;i<n;i++)cin>>a[i]
#define output(a,n) for(long long i=0;i<n;i++)cout<<a[i]<<" "
#define     she_taught_me_to_code cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ep 1e-10
#define pi pair<ll,ll>
#define inf 10e9
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
ll gcd(ll a,ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm1(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
#define N 1000000
vector<ll> adj[N];
vector<bool> visited(N,0);
ll DFSUtil(ll u,ll last)
{
    visited[u] = true;
    for (ll i=0; i<adj[u].size(); i++)
    {
        if (visited[adj[u][i]] == false)
        {
            if(DFSUtil(adj[u][i],u)==-1)
            {
                if(adj[u][i]!=last)
                    return -1;
            }
        }
        else if(adj[u][i]!=last)
            return -1;
    }
    return 0;
}
ll DFS(ll n)
{
    for (ll u=0; u<n; u++)
    {
        if (visited[u] == false)
        {
            if(DFSUtil(u,0)==-1)
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
int main()
{
    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("input.txt","w",stdout);

    aE(1,2);
    aE(2,3);
    aE(3,4);
  //  aE(4,1);
    aE(1,5);
    cout<<DFS(5)<<endl;
}
