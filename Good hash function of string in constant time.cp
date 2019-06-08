
//.       Function 1

set<ll> ans[1600];
string s;
cin>>s;
ll n=s.size();
for(ll i=0;i<n;i++)
{
    ll qh=0;
    for(ll j=i;j<n;j++)
    {
        qh=qh*117+s[j];
        ans[j-i+1].insert(qh);
        string c(s.begin()+i,s.begin()+j+1);
        cout<<c<<" "<<j-i+1<<" "<<qh<<endl;
    }
}
ll answ=0;
for(int i=1;i<=1500;i++)
{
    answ+=ans[i].size();
}
cout<<answ<<endl;


//.       Function 2
// define seed as 13331

map<ll,ll> m;
ll ans=0;
string s;
cin>>s;
ll n=s.size();
ll hash[1500],ex[1500];
ex[0]=1;
for(int i=1;i<=n;i++)
    ex[i]=ex[i-1]*seed;
for(int i=1;i<=n;i++)
    hash[i]=(hash[i-1]*seed+s[i]);
for(ll i=0;i<n;i++)
{
    for(ll j=i;j<n;j++)
    {
        long long t=(hash[j]-hash[i-1]*ex[j-i+1]);
        if(!m.count(t))
        {
            m[t]=true;
            ans++;
        }
    }
}
cout<<ans<<endl;
