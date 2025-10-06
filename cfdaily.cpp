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
vector<vll>c;
vector<vll>dp(21,vll(1<<21,-1));

long long helper(int i, int n, long long &mask){
     if(i==n+1){
          return 0;
     }

     
}

void solve()
{
     // int n;
     // cin>>n;

     // c=vector<vll>(n,vll(n));
     // dp=vector<vll>(21,vll(1<<21,-1));
     // loop(0,n){
     //      for(int j=0;j<n;j++){
     //           cin>>c[i][j];
     //      }
     // }
     int n;
     cin>>n;
     int cnt=0;
     int wg=n;
     int lg=0;
     while (wg>1||lg>1)
     {
          int nlg=wg/2;
          cnt+=wg/2;
          int nwg=wg/2+wg%2;
          cnt+=lg/2;
          nlg+=lg/2+lg%2;
          wg=nwg;
          lg=nlg;
     }
     cnt++;
     cout<<cnt<<endl;
}
int main()
{
     int t = 1;
     cin >> t;
     for (int j = 0; j < t; j++)
     {
          solve();
     }
     return 0;
}