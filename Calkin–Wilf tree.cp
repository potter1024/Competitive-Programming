int main()
{
    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ll a,b,count=0;
    cin>>a>>b;
    while(1)
    {
        count++;
        if(a>b)
        {
            a += b;
        }
        else if(a<b)
        {
            b -= a;
        }
        else
        {
            break;
        }
    }
    
    // both are same but with diffeent complexities
    
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            count += a / b;
            a %= b;
        }
        else
        {
            count += b / a;
            b %= a;
        }
    }
    cout<<count;
    
    // gcd function to calculate total steps to move from any a/b to 1/1 in the tree
    
    ll gcd(ll a,ll b,ll count)
    {
        if (b == 0)
            return count;
        return gcd(b, a % b,count+a/b);
    }
}
