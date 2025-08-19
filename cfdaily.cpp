#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define loop(j, n) for (int i = j; i < n; i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ll> vll;

const int M = 1e9 + 7;
int get_bit(ll n, ll pos)
{
    return (n & (1LL << pos)) != 0;
}
ll set_bit(ll n, int pos)
{
    n = n | (1 << pos);
    return n;
}
ll clear_bit(ll n, int pos)
{
    int ele = 1 << pos;
    ele = ~ele;
    n = n & ele;
    return n;
}
void update_bit(int &n, int pos, int value)
{
    int mark = ~(1 << pos);
    n = n & mark;
    n = n | (value << pos);
}
ll gcd(ll a, ll b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    ll ele = a * b;
    ll ele1 = gcd(a, b);
    return ele / ele1;
}
ll binexp(ll a, ll b, ll m)
{
    ll result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}
ll modexp(ll a)
{
    return binexp(a, M - 2, M);
}

bool checker(string s, string t, int mid){
    int i=0;
    int j=0;
    while(j<t.size() && i<s.size()){
        if(s[i]==t[j]){
            i+=mid;
            j++;
        }
        else{
            i++;
        }
    }
    if(j<t.size()){
        return false;
    }
    return true;
}

vi helper(string s, string ex){
    int n=s.size();
    vi v(n);
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==ex[j]){
            v[i]=0;
        }
        else{
            v[i]=1;
        }
        j=(j+1)%3;
    }
    loop(1,n){
        v[i]+=v[i-1];
    }
    return v;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vvi arr(6);
    arr[0]=helper(s,"abc");
    arr[1]=helper(s,"acb");
    arr[2]=helper(s,"bac");
    arr[3]=helper(s,"bca");
    arr[4]=helper(s,"cab");
    arr[5]=helper(s,"cba");
    while(m--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        int ans=n;
        for (int j = 0; j < 6; j++)
        {
            int tmp=0;
            if(l-1>=0){
                tmp=arr[j][l-1];
            }
            ans=min(ans,arr[j][r]-tmp);
        }
        cout<<ans<<endl;
    }
    // cout<<endl;
}
int main()
{
    int t;
    t=1;
    // cin >> t;
    for (int j = 0; j < t; j++)
    {
        solve();
    }
    return 0;
}