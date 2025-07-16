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
const int M = 1000000007;
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

void helper(string curr, int n, vector<string> &v)
{
    if (n == 0)
    {
        v.push_back(curr);
        return;
    }
    helper(curr + "0", n - 1, v);
    helper(curr + "1", n - 1, v);
}
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

vector<pair<pair<ll, ll>, pair<ll, ll>>> v;
ll dfs(vvi &adj, int n, int i, vector<bool> &vis)
{
    if (vis[i])
    {
        return 0;
    }
    ll ans = v[i].second.second;
    vis[i] = true;

    ll tmp = 0;
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            tmp = max(tmp, dfs(adj, n, j, vis));
        }
    }
    // vis[i]=false;
    return ans + tmp;
}

bool checker(ll mid, ll n, ll m, ll k)
{
    ll s1 = 0;
    ll e1 = m;
    ll a1 = 0;

    while (s1 <= e1)
    {
        ll x = (s1 + e1) / 2;
        if ((x - 1) * (mid + 1) + mid <= m)
        {
            a1 = max(a1, x);
            s1 = x + 1;
        }
        else
        {
            e1 = x - 1;
        }
    }
    ll tmp = a1 * mid;
    if ((m - (a1 - 1) * (mid + 1) - mid) > 0)
    {
        tmp += m - (a1 - 1) * (mid + 1) - mid - 1;
    }
    return (tmp * n >= k);
}

vll fac;

void solve()
{
    ll n, r;
    cin >> n >> r;
    // cout<<fac[100000]<<endl;
    ll num = fac[n - 1]%M;
    ll denom1 = fac[n - r]%M;
    ll denom2 = fac[r - 1]%M;
    ll dnum1 = modexp(denom1)%M;
    ll ans = ((num%M) * (dnum1%M)) % M;
    ll dnum2 = modexp(denom2)%M;
    ans = ((ans%M) * (dnum2%M)) % M;
    cout << ans << endl;
}

int main()
{
    fac = vll(1e5 + 1, 1);
    for (int i = 1; i <= 1e5; i++)
    {
        fac[i] = ((i%M) * (fac[i - 1]%M)) % M;
    }
    int t;
    // t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}