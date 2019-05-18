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
#define MAX 1000000
ll id[MAX]={};
ll sz[MAX]={};
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
int main()
{
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
    {
        id[i]=i;
        sz[i]=1;
    }
    while(k--)
    {
        ll a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<sz[root(i)]<<" ";
    }
}
