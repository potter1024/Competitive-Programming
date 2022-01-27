                                           //    Most used string algorithms

//  1. Longest prefix which is also suffix

ll dp[n];                               // dp[i] will store the longest prefix which is also suffix
dp[0]=0;
for(ll i=1;i<n;i++)
{
    int j=dp[i-1];
    while(j>0 && s[j]!=s[i])
        j=dp[j-1];
    if(s[j]==s[i])
        j++;
    dp[i]=j;
}

//  2. All prefix which is also suffix

vi all;                                       // all will contain the length of all prefix which is also suffix
ll x=n-1;
while(dp[x]>0)
{
    all.pb(dp[x]);
    x=dp[x]-1;
}

// 3. Number of occurence of a prefix in the string

vi occ(n + 1);                        //  occ[i] will store the number of occurence of prefix of length i in the string
for (ll i = 0; i < n; i++)
    occ[dp[i]]++;
for (ll i = n-1; i > 0; i--)
    occ[dp[i-1]] += occ[i];
for (ll i = 0; i <= n; i++)
    occ[i]++;

// 4. Count the number of distinct substrings in a string

ll sum=0;                             // sum will store the required value.   empty substring is not included
for(ll i=1;i<=n;i++)
    sum+=(i-dp[i-1]);
