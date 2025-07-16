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
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    vll arr(n);
    loop(0,n){
        cin>>arr[i];
    }
    // loop(0,n){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    
    vll pre(n);
    pre[0]=arr[0];
    loop(1,n){
        pre[i]=max(pre[i-1],arr[i]);
    }
    // loop(0,n){
    //     cout<<pre[i]<<" ";
    // }
    // cout<<endl;
    
    vll pos(n);
    vll posm(n);
    posm[n-1]=arr[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        posm[i]=max(posm[i+1],arr[i]);
    }
    map<ll,ll>m1;
    set<ll>st;
    m1[arr[n-1]]=n-1;
    st.insert(arr[n-1]);
    pos[n-1]=1;
    for (int i = n-2; i >= 0; i--)
    {
        auto idx=st.upper_bound(arr[i]);
        if(idx!=st.end()){
            pos[i]=m1[*idx];
        }
        else{
            m1[arr[i]]=1;
        }
    }
    loop(0,n){
        int idx1=i;
        int s=0;
        int e=i;
        while (s<=e)
        {
            int mid=(s+e)/2;
            if(pre[mid]>=arr[i]){
                idx1=min<ll>(idx1,arr[i]);
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        
        int idx2=pos[i]-1;
        cout<<idx1<<" "<<idx2<<endl;
        if(idx1+idx2>=k){
            cout<<arr[i]<<endl;
            return;
        }
    }
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