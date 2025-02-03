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
     int n,m1,m2;
     cin>>n>>m1>>m2;
     set<pair<int,int>>set1;
     set<pair<int,int>>set2;
     loop(0,m1){
          int u,v;
          cin>>u>>v;
          if(u>v){
               swap(u,v);
          }
          set1.insert({u,v});
     }
     loop(0,m2){
          int u,v;
          cin>>u>>v;
          if(u>v){
               swap(u,v);
          }
          set2.insert({u,v});
     }
     int count=0;
     for(auto i:set1){
          if(set2.find(i)==set2.end()){
               count++;
          }
     }
     for(auto i:set2){
          if(set1.find(i)==set1.end()){
               count++;
          }
     }
     cout<<count<<endl;
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