int mod(string num, int a)                //calculate num%a
{
    int res = 0;

    for (int i = 0; i < num.length(); i++)
    {
        res = (res*10 + (int)num[i] - '0') %a;
        cout<<res<<endl;
    }
    return res;
}
