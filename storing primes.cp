int a[100005]={};
vi v;
for(ll i=2;i*i<=100005;i++)                  // runs in O(n*log(log(n)))
{
   if(a[i]==1)
      continue;
   for(ll j=i*i;j<=100005;j+=i)
      a[j]=1;
}
for(ll i=2;i<100005;i++)
    if(a[i]==0)
        v.pb(i);
