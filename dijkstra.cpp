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
int dijkstra(vector<vector<vector<long long>>> &adj, int i, int n)
{
     vector<int> cnt(n, 0);
     cnt[0] = 1;
     vector<long long> dis(n, INT64_MAX);
     priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
     dis[i] = 0;
     pq.push({0, i});
     while (pq.size() > 0)
     {
          long long curr_dis = pq.top().first;
          long long node = pq.top().second;
          pq.pop();
          for (auto it : adj[node])
          {
               long long edgeWeight = it[1];
               long long adjNode = it[0];

               if (curr_dis + edgeWeight < dis[adjNode])
               {
                    cnt[adjNode] = cnt[node];
                    dis[adjNode] = curr_dis + edgeWeight;
                    pq.push({dis[adjNode], adjNode});
               }
               else if (curr_dis + edgeWeight == dis[adjNode])
               {
                    cnt[adjNode] = (cnt[adjNode] % ((int)1e9 + 7) + cnt[node] % ((int)1e9 + 7)) % ((int)1e9 + 7);
               }
          }
     }
     // return 0;
     return cnt[n - 1];
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
