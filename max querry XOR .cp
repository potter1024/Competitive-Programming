//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <cmath>
#include<math.h>
#include <set>
#include <time.h>
#include <map>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <numeric>
#include <unordered_map>
using namespace std;
#define sz(a) int((a).size())
#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define vi vector<ll>
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define rep(i,n) for(ll i=0;i<n;i++)
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define input(a,n) for(long long i=0;i<n;i++)cin>>a[i]
#define output(a,n) for(long long i=0;i<n;i++)cout<<a[i]<<" "
#define     she_taught_me_to_code cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ep 1e-10
#define pi pair<ll,ll>
#define inf 10e9
#define N 1000000
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
ll gcd(ll a,ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm1(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
//    Defining of root node:  TrieNode *root=new TrieNode();
struct TrieNode
{
    map<char,TrieNode*> children;
    int count=0;
};
TrieNode *root=new TrieNode();
void insert(string word)
{
    TrieNode *current=root;
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
        {
            node=new TrieNode();
            current->children[ch]=node;
        }
        current=node;
        current->count++;
    }
}
string maXOR(string word)
{
    TrieNode *current=root;
    string s;
    for(int i=0;i<word.size();i++)
    {
        TrieNode *node;
        if(word[i]=='0')
        {
            node=current->children['1'];
            if(!node)
            {
                node=current->children['0'];
                s.pb('0');
            }
            else
            {
                s.pb('1');
            }
        }
        else
        {
            node=current->children['0'];
            if(!node)
            {
                node=current->children['1'];
                s.pb('0');
            }
            else
            {
                s.pb('1');
            }
        }
        current=node;
    }
    return s;
}
void deletion(string word)
{
    TrieNode *current=root;
    for(ll i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch],*prev;
        prev=current;
        current=node;
        current->count--;
        if(current->count==0)
        {
            prev->children[ch]=NULL;
        }
    }
}
int main()
{
    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("input.txt","w",stdout);

    string s;
    for(ll i=0;i<32;i++)
    {
        s.pb('0');
    }
    insert(s);
    ll n;
    cin>>n;
    while(n--)
    {
        char c;
        cin>>c;
        if(c=='+')
        {
            ll a;
            cin>>a;
            string s;
            while(a!=0)
            {
                s.pb((char)(a%2+48));
                a/=2;
            }
            ll l=s.size();
            for(ll i=0;i<32-l;i++)
            {
                s.pb('0');
            }
            reverse(all(s));
            insert(s);
        }
        else if(c=='-')
        {
            ll a;
            cin>>a;
            string s;
            while(a!=0)
            {
                s.pb((char)(a%2+48));
                a/=2;
            }
            ll l=s.size();
            for(ll i=0;i<32-l;i++)
            {
                s.pb('0');
            }
            reverse(all(s));
            deletion(s);
        }
        else
        {
            ll a,ans=0;
            cin>>a;
            string s;
            while(a!=0)
            {
                s.pb((char)(a%2+48));
                a/=2;
            }
            ll l=s.size();
            for(ll i=0;i<32-l;i++)
            {
                s.pb('0');
            }
            reverse(all(s));
            s=maXOR(s);
            for(ll i=0;i<32;i++)
            {
                ans+=(s[i]=='1')?pow(2,31-i):0;
            }
            cout<<ans<<endl;
        }
    }

}
