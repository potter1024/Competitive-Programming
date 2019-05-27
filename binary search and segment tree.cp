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
vector<ll> v(N,0),tree(N,0);
void build(ll node, ll start, ll end)          // initial call is build(1,0,n-1)
{
    if(start == end)
    {
        tree[node] = v[start];
    }
    else
    {
        ll mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] * tree[2*node+1];
    }
}
ll query(ll node, ll start, ll end, ll l, ll r)
{
    if(r < start || end < l)
    {
        return 1;
    }
    if(l <= start && end <= r)
    {
        return tree[node];
    }
    ll mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 * p2);
}
void update(ll node, ll start, ll end, ll idx, ll val)
{
    if(start == end)
    {
        v[idx] += val;
        tree[node] += val;
    }
    else
    {
        ll mid = (start + end) / 2;
        if(start <= idx && idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] * tree[2*node+1];
    }
}
int main()
{
    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("input.txt","w",stdout);

    //Finding number of subsets whose product is divisible by k. Cutting down a naive complexity of n^3 to n(logn)^2
    v[0]=6;
    v[1]=2;
    v[2]=8;
    ll n=3,ans=0,k=4;
    build(1,0,n-1);
    for(ll i=0;i<n;i++)
    {
        ll start=i,end=n-1,mid,mine=n-1;
        while(start!=end)
        {
            mid=(start+end)/2;
            if(query(1,0,n-1,i,mid)%k==0)
            {
                end=mid-1;
                mine=min(mine,mid);
            }
            else
            {
                start=mid+1;
            }
        }
        cout<<i<<" "<<mine<<endl;
        ans+=n-mine;
    }
    cout<<ans<<endl;
}
