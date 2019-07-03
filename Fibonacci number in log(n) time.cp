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
#define pi                  pair<ll,ll>
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
#define inputt(a,n,m)       for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)cin>>a[i][j]
#define outputt(a,n,m)      for(ll i=0;i<n;i++){for(ll j=0;j<m;j++)cout<<a[i][j]<<"";cout<<endl;}
#define reset(a,n)          memset(a,n,sizeof(a))   // n can only be 0 or -1
#define vl                  LLONG_MIN
#define vm                  LLONG_MAX
#define ep                  1e-10
#define seed                13331
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
// If MLE occurs, try declaring the large array in int instead of long long
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
ll min(ll a,ll b)
{
    return a<b?a:b;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}
string s;
ll n,m;
vi v(1005,1);
bool is_sorted(ll l,ll r)
{
    for(ll i=l+1;i<=r;i++)
    {
        if(v[i]<v[i-1])
            return 0;
    }
    return 1;
}
struct mat
{
    ll a,b,c,d;
};
mat po(ll n)
{
    if(n==1)
    {
        mat in;
        in.a=1;
        in.b=1;
        in.c=1;
        in.d=0;
        return in;
    }
    if(n==2)
    {
        mat in;
        in.a=2;
        in.b=1;
        in.c=1;
        in.d=1;
        return in;
    }
    else
    {
        mat a=po(n/2);
        mat b;
        b.a=(a.a)*(a.a)+(a.b)*(a.c);
        b.b=(a.a)*(a.b)+(a.b)*(a.d);
        b.c=(a.a)*(a.c)+(a.c)*(a.d);
        b.d=(a.b)*(a.c)+(a.d)*(a.d);
        b.a%=M;
        b.b%=M;
        b.c%=M;
        b.d%=M;
        if(n%2==1)
        {
            mat c;
            c.a=b.a+b.b;
            c.b=b.a;
            c.c=b.c+b.d;
            c.d=b.c;
            c.a%=M;
            c.b%=M;
            c.c%=M;
            c.d%=M;
            return c;
        }
        return b;
    }
}
int32_t main()
{
    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ll n;
    cin>>n;
    mat re=po(n);
    cout<<re.c<<" ";
}
