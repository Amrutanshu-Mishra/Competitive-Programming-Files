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
vector<long long> dijkstra(vector<vector<vector<long long>>>&adj,int n,int src){
     vector<long long>ans(n,1e11);
     ans[src]=0;
     set<pair<long long,long long>>se1;
     se1.insert({0,src});
     while (se1.size()>0)
     {
          pair<long long,long long>p1=*(se1.begin());
          int node=p1.second;
          int dis=p1.first;
          se1.erase(p1); 
          for(auto i:adj[node]){
               int adjNode=i[0];
               int edgW=i[1];
               if(dis+edgW<ans[adjNode]){
                    if(ans[adjNode]!=1e11){
                         se1.erase({ans[adjNode],adjNode});
                    }
                    ans[adjNode]=dis+edgW;   
                    se1.insert({ans[adjNode],adjNode});
               }
          }
     }
     return ans;
}
void solve()
{
     int n;
     cin >> n;
     vll arr(n);
     loop(0, n)
     {
          cin >> arr[i];
     }
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