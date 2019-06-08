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
