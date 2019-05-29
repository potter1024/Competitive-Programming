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
int main()
{
    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
            cin>>a[i][j];
    }
    int up=0,down=n-1,left=0,right=m-1;
    vector<int> v;
    while(1)
    {
        for(int i=left;i<=right;i++)
        {
            v.push_back(a[up][i]);
        }
        for(int i=up+1;i<=down;i++)
        {
            v.push_back(a[i][right]);
        }
        if(down!=up)
        {
            for(int i=right-1;i>=left;i--)
            {
                v.push_back(a[down][i]);
            }
        }
        if(left!=right)
        {
            for(int i=down-1;i>up;i--)
            {
                v.push_back(a[i][left]);
            }
        }
        left++;
        right--;
        up++;
        down--;
        if(left>right || up>down)
            break;
    }
    for(ll i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
