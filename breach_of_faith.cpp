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
void solve()
{
    int n;
    cin >> n;
    vll arr(2 * n);
    map<ll,bool>vis;
    loop(0, 2 * n)
    {
        cin >> arr[i];
        vis[arr[i]]=true;
    }
    sort(arr.begin(),arr.end());
    int idx = -1;
    ll num = -1;
    vll dp1(2 * n, 0);
    vll dp2(2 * n, 0);
    dp1[0] = arr[0];
    dp1[1] = arr[1];
    loop(2, 2 * n)
    {
        dp1[i] = arr[i] + dp1[i - 2];
    }

    dp2[2*n-1]=arr[2*n-1];
    dp2[2*n-2]=arr[2*n-2];
    for (int i = 2*n-3; i >= 0; i--)
    {
        dp2[i]=arr[i]+dp2[i+2];
    }
    
    loop(0,2*n){
        ll a=0;
        ll b=0;
        if(i-1>=0){
            a=dp1[i-1];
        }
        if(i+1<2*n){
            b+=dp2[i+1];
        }
        b+=dp1[i];
        if(i+2<2*n){
            a+=dp2[i+2];
        }
        if(b>a && !vis[b-a]){
            idx=i;
            num=b-a;
            break;
        }
    }

    loop(0,n*2){
        cout<<arr[i]<<" ";
        if(i==idx){
            cout<<num<<" ";
        }
        
    }
    cout<<endl;
}
int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        solve();
    }
    return 0;
}