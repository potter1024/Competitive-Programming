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
#define MAX_N 100010
string s,pat;
ll b[MAX_N], n, m;
void kmpPreprocess()
{
    ll i = 0, j = -1; b[0] = -1;
    while (i < m)
    {
        while (j >= 0 && pat[i] != pat[j])
            j = b[j];
        i++;
        j++;
        b[i] = j;
    }
}
vi found;
void kmpSearch()
{
    kmpPreprocess();
    ll i = 0, j = 0;
    while (i < n)
    {
        while (j >=0 && s[i] !=pat[j])
            j = b[j];
        i++;
        j++;
        if (j == m)
        {
            found.pb(i-j);
            j = b[j];
        }
    }
}
int main()
{
    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    cin>>s>>pat;
    n=s.size();
    m=pat.size();
    kmpSearch();
    output(found,found.size())<<endl;

}
