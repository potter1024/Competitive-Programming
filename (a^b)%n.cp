ll modulo(ll a, ll b, ll n)             //calculate (a^b)%n
{
    long long x=1, y=a;
    while (b > 0)
    {
        if (b%2 == 1)
        {
            x = (x*y) % n;
        }
        y = (y*y) % n;
        b /= 2;
    }
    return x % n;
}
