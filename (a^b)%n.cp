ll power(ll a,ll b)
{
    if(b==0)
        return 1;
    ll x=power(a,b/2);
    x*=x;
    x%=M;
    if(b%2)
        x*=a;
    x%=M;
    return x;
}
