// It is calculating Σ⊕(i%j) where 1<=i<=n and 1<=j<=n in O(n) time complexity


vi XorPref(N,0);
for(int i = 1; i < 1000000; ++ i)
    XorPref[i] = XorPref[i - 1] ^ i;
ll Q=0;
for(ll j = 1; j <= n; ++ j)
{
    ll CntBlocks = n / j;
    if(CntBlocks % 2)
        Q ^= XorPref[j - 1];
    ll Rem = n % j;
     Q ^= XorPref[Rem];
}
cout<<Q<<endl;
