ll dis(pair<ll,ll> a,pair<ll,ll> b)
{
    return((a.first-b.first)*(a.first-b.first) +(a.second-b.second)*(a.second-b.second));
}
bool is_square(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c,pair<ll,ll> d )
    {
    ll d1=dis(a,b);
    ll d2=dis(a,c);
    ll d3=dis(a,d);
    ll d4=dis(b,c);
    ll d5=dis(b,d);
    ll d6=dis(c,d);
    map<ll,ll> m;
    m[d1]++;m[d2]++;m[d3]++;m[d4]++;m[d5]++;m[d6]++;
    if((int)m.size()==2)
    {
        auto it=m.begin();
        ll x=it->first;
        it++;
        ll y=it->first;
        if(y==2*x)
            return true;
        else 
            return false;
    }
    return false;
}
