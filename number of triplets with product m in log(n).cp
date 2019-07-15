int countTriplets(int a[], int m, int n)
{

    unordered_map<int, int> f;
    set<pair<int, pair<int, int> > > st;
    for (int i = 0; i < n; i++)
        f[a[i]] += 1;
    int ans = 0;
    for (int i = 1; i * i <= m; i++)
    {
        if (m % i == 0 && f[i])
        {
            int num1 = m / i;
            for (int j = 1; j * j <= num1; j++)
            {
                if (num1 % j == 0 and f[j])
                {
                    int num2 = num1 / j;
                    if (f[num2])
                    {
                        int temp[] = { num2, i, j };
                        sort(temp, temp + 3);
                        int setsize = st.size();
                        st.insert({ temp[0], { temp[1], temp[2] } });
                        if (setsize != st.size())
                        {
                            if (i != j and j != num2)
                                ans += f[i]*f[j]*f[num2];
                            else if (i == j && j != num2)
                                ans += (f[i]*(f[i]-1)/2)*f[num2];
                            else if (j == num2 && j != i)
                                ans += (f[j]*(f[j]-1)/2)*f[i];
                            else if (i == j and j == num2)
                                ans+=(f[i]*(f[i]-1)*(f[i]-2)/6);
                            else
                                ans+=(f[i]*(f[i]-1)/2)*f[j];
                        }
                    }
                }
            }
        }
    }
    return ans;
}
