#include <bits/stdc++.h>
#include <iomanip>
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

void dfs(int node, int parent, vi &depth, vector<vector<int>>&adj){
    for(auto adjNode:adj[node]){
        if(adjNode==parent){
            continue;
        }
        depth[adjNode]=1+depth[node];
        dfs(adjNode, node, depth, adj);
    }
}

int find_diameter(vector<vector<int>>&adj, int n, vi &depth1, vi &depth2){
    depth1[0]=0;
    dfs(0, -1, depth1, adj);
    int node1=-1;
    int maxDepth=-1;

    for(int i=0;i<n;i++){
        if(maxDepth<depth1[i]){
            maxDepth=depth1[i];
            node1=i;
        }
    }

    depth2[node1]=0;
    dfs(node1, -1, depth2, adj);
    int node2=node1;
    node1=-1;
    maxDepth=-1;
    for(int i=0;i<n;i++){
        if(maxDepth<depth2[i]){
            maxDepth=depth2[i];
            node1=i;
        }
        depth1[i]=0;
    }

    dfs(node1, -1, depth1, adj);
    return maxDepth;
}

void solve()
{
    int n;
    cin>>n;
    
    vector<vector<int>>adj1(n);
    loop(0,n-1){
        int u,v;
        cin>>u>>v;

        u--;v--;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    int m;
    cin>>m;

    vector<vector<int>>adj2(m);
    loop(0,m-1){
        int u,v;
        cin>>u>>v;

        u--;v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }    

    vi depth1(n, n+1);
    vi depth2(n, n+1);
    vi depth3(m, m+1);
    vi depth4(m, m+1);

    int d1=find_diameter(adj1, n, depth1, depth2);
    int d2=find_diameter(adj2, m, depth3, depth4);

    int ans1=1e5;
    int ans2=1e5;
    loop(0,n){
        ans1=min(ans1, max(depth1[i], depth2[i]));
    }
    loop(0,m){
        ans2=min(ans2, max(depth3[i], depth4[i]));
    }

    // cout<<ans1<<" "<<ans2<<endl;
    cout<<max({d1,ans1+ans2+1,d2})<<endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    for (int j = 0; j < t; j++)
    {
        solve();
    }
    return 0;
}