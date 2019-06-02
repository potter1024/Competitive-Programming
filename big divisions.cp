// calculating big divisions
// here this is calculating nCk i.e n! / ((n-i)!i!) where num and parts of denominator are available in %M

ll power(ll base,ll exp)
{
    if(exp==0)
        return 1;
    ll x=power(base,exp/2);
    x*=x;
    x%=M;
    if(exp%2==0)
        return x;
    else
        return (x*base)%M;
}
ll getc(ll n,ll k)
{
    ll num=factorial[n];
    ll den=factorial[k]*factorial[n-k];
    den%=M;
    den=power(den,M-2)%M;
    return (num*den)%M;
}
