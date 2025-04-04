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
    string s;
    cin>>s;
    ll n=s.size();
    ll pos;
    cin>>pos;
    // if(s.size()==1){
    //     cout<<s[0]<<endl;
    //     return;
    // }
    ll st=0;
    ll e=s.size();
    ll ans=s.size();
    while (st<=e)
    {
        ll mid=(st+e)/2;
        ll tmp=n*(n+1)/2-(n-mid)*(n-mid-1)/2;
        if(tmp>=pos){
            ans=min(ans,mid);
            e=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    pos-=n*(n+1)/2-(n-ans)*(n-ans+1)/2;
    pos--;
    // cout<<ans<<" "<<pos<<endl;

    vector<int>v1(26,n);
    vector<set<pair<int,int>>>v2(n+1);
    for(int i=n-1;i>=0;i--){
        int idx=n;
        for(int j=0;j<(s[i]-'a');j++){
            if(v1[j]!=n){
                idx=min(idx,v1[j]);
            }
        }
        
        v1[s[i]-'a']=min(v1[s[i]-'a'],i);
        v2[idx].insert({26-(s[i]-'a'),i});
    }
    // for(int i=0;i<=n;i++){
    //     cout<<i<<": ";
    //     for(auto j:v2[i]){
    //         cout<<j.second<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int>tmp;
    for(int i=0;i<=n;i++){
        for(auto j:v2[i]){
            tmp.push_back(j.second);
        }
    }
    map<int,int>m1;
    for(int i=0;i<tmp.size();i++){
        m1[tmp[i]]=i+1;
    }
    
    string s3="";
    for(int i=0;i<n;i++){
        if(m1[i]<=ans){
            continue;
        }
        s3+=s[i];
    }
    cout<<s3[pos];
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