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
ll fact[5005];
#define mod 1000000007
ll fac(ll n){
    if(fact[n]){
        return fact[n];
    }
    if(n==0){
        return 1;
    }
    return (fac(n-1)*n)%mod;
}
ll solve(ll n,ll r){
    ll x1=fac(n-r);
    ll x2=fac(r);
    x1=po(x1,mod-2,mod);
    x2=po(x2,mod-2,mod);
    ll ans=fac(n);
    ans*=x1;
    ans%=mod;
    ans*=x2;
    ans%=mod;
    return ans;
}
