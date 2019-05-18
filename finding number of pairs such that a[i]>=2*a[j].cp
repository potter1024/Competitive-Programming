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
int main()
{
    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("input.txt","w",stdout);

    ll n;
    cin>>n;
    vi v(n);
    rep(i,n)
        cin>>v[i];
    sort(allr(v));
    ll j=0,ans=0;
    for(ll i=1;i<n;i++)
    {
        while(2*v[i]<v[j] && j<i)
        {
            j++;
        }
        ans+=(i-j);
    }
    cout<<ans;
}
