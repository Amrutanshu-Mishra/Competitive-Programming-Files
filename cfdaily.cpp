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

bool checker(ll mid,ll n,ll m,ll k){
    ll s1=0;
    ll e1=m;
    ll a1=0;
    
    while(s1<=e1){
        ll x=(s1+e1)/2;
        if((x-1)*(mid+1)+mid<=m){
            a1=max(a1,x);
            s1=x+1;
        }
        else{
            e1=x-1;
        }
    }
    ll tmp=a1*mid;
    if((m-(a1-1)*(mid+1)-mid)>0){
        tmp+=m-(a1-1)*(mid+1)-mid-1;
    }
    return (tmp*n>=k);
}
void solve()
{
    ll n;

}
int seive[10000000+1];
int dp[10000000+1];
int main()
{
    for(int i=0;i<=10000000;i++){
        seive[i]=i;
    }
    
    for(int i=2;i*i<=10000000;i++){
        if(seive[i]==0){
            for(int j=i*i;j<=10000000;j+=i){
                seive[j]=i;
            }
            // seive[i]=1;
        }
    }
    for(int i=0;i<=20;i++){
        cout<<seive[i]<<" ";
    }
    cout<<endl;
    cout<<seive[2]<<endl;
    // int t;
    // t = 1;
    // cin >> t;
    // while (t--)
    // {
    //     ll n;
    //     cin>>n;
    //     ll fin=0;
        
    //     for(int i=n;i>0;i--){
            
    //         fin+=seive[i];
    //     }
    //     cout<<fin<<endl;
    // }
}
