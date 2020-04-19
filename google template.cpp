#include <bits/stdc++.h>
using namespace std;
#define sz(a)               ll((a).size())
#define ll                  long long
#define int                 ll
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
#define output(a)           for(long long i=0;i<a.size();i++)cout<<a[i]<<" "
#define reset(a,n)          memset(a,n,sizeof(a))   // n can only be 0 or -1
#define ep                  1e-10
#define pi                  pair<ll,ll>
#define inf                 LLONG_MAX
#define N                   1000000
#define minp                vector<ll>, greater<ll>
#define M                   1000000007
#define MM                   1000000009
#define pie                 3.1415926535897932384626433832795
#define eu                  2.718281828459045
#define                     she_taught_me_to_code cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);cin.tie(NULL);    clock_t startTime=clock(); cout<<fixed<<setprecision(12);
#define time     cout<<(double(clock()-startTime )/(double)CLOCKS_PER_SEC)*1000<<" ms"<<endl;
#define debug(k) cout<<"\t-> "<<#k<<" = "<<k<<endl;

/************************************Debugging Tips****************************************/

// If aplying ceil, floor, pow, etc convert it llo lleger
// Whenever using stacks,queues,etc always check that their top / front / back elements are not accessed when they are empty, thus causing runtime error
// Think twice before using greedy
// Remember losing 1 or 2 minutes is better than a penalty of 10 minutes
// Use log2 instead of log()/log(2) to avoid shitty errors
// If declaring a large array, define it globally
// Always initialise anything while declaring, which will not be taken as input
// In case of a problem having decimal calculations, try declaring everything in double rather than typecasting in each step
// Always declare the array with n+5 elements to avoid unexpected errors
// Every problem cannot be solved by DFS easily, think of BFS too
// Never use accumulate
// Use __builtin_popcountll(mask) for counting number of set bits in mask to avoid TLE
// In some problems it has some constant solution for large n and a polynomial solution for small n so that it can be easily solved, keep that in mind
// Use upper_bound(all(v),x,greater<ll>()) for reverse of upper_bound, i.e finding greatest element less than x, v should be reverse sorted
// Use s.lower_bound(x) in set and multiset, the other one has linear complexity

ll gcd(ll a,ll b){
    return b?gcd(b, a % b):a;
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
ll min(ll a,ll b){
    return a<b?a:b;
}
ll max(ll a,ll b){
    return a>b?a:b;
}
ll max3(ll a,ll b,ll c){
    return max(max(a,b),c);
}
ll max4(ll a,ll b,ll c,ll d){
    return max(max(a,b),max(c,d));
}
ll min3(ll a,ll b,ll c){
    return min(min(a,b),c);
}
ll min4(ll a,ll b,ll c,ll d){
    return min(min(a,b),min(c,d));
}
ll po(ll x,ll n,ll mod=M){
    if(n==0){
        return 1;
    }
    ll m=po(x,n/2,mod);
    m*=m;
    m%=mod;
    if(n%2){
        m*=x;
        m%=mod;
    }
    return m;
}
void solve(){

}
int32_t main(){

    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("input.txt","w",stdout);

    ll d;
    cin>>d;
    for(ll i=1;i<=d;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
