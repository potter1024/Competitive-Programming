ll a[5000005]={};
    for(ll i=2;i<=5000000;i++){
        if(a[i]==0){
            for(ll j=i*i; j<=5000000; j+=i){
                if(a[j]==0){
                    a[j]=i;
                }
            }
        }
    }
    ll dp[5000005]={};
    for(int i=2;i<=5000000;i++){
        if(a[i]==0){
            dp[i]=1;
        }
        else{
            dp[i]=1+dp[i/a[i]];
        }
    }
