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

bool checker(vll &roo, vll &rou, int n, int m, ll mid)
{
    loop(0, n)
    {
        int idx1 = lower_bound(rou.begin(), rou.end(), roo[i] - mid) - rou.begin();
        if (idx1 == m)
        {
            return false;
        }
        if (abs(roo[i] - rou[idx1]) <= mid)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool cmp(pair<pair<ll, ll>, pair<ll, ll>> a, pair<pair<ll, ll>, pair<ll, ll>> b)
{
    if (a.second.first != b.second.first)
    {
        return a.second.first < b.second.first;
    }
    return a.second.second < b.second.second;
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
void solve()
{
    int n,k;
    cin>>n>>k;
    vll arr(n);
    loop(0,n){
        cin>>arr[i];
    }
    if(k>=2){
        sort(arr.begin(),arr.end());
        ll ans=0;
        for(int i=0;i<=k;i++){
            ans+=arr[n-i-1];
        }
        cout<<ans<<endl;
        return;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(i==0){
            ans=max(ans,arr[0]+arr[n-1]);
        }
        else if(i==n-1){
            ans=max(ans,arr[0]+arr[n-1]);
        }
        else{
            ans=max(ans,arr[i]+max(arr[0],arr[n-1]));
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
