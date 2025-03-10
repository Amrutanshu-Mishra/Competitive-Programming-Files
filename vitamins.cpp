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

ll helper(vll &arr, int n, int j, ll x, vector<unordered_map<int, ll>> &dp)
{
     if (j == n)
     {

          if (x == 0)
          {
               return 1;
          }
          return 0;
     }
     if (x < 0)
     {
          return 0;
     }
     if (x == 0)
     {
          return 1;
     }
     if(arr[j]>x){
          return 0;
     }
     if (dp[j][x] != 0)
     {
          return dp[j][x] - 1;
     }
     ll ans = 0;
     
     // cout <<n<<" " <<j << " " << x << " " << ans << endl;
     ll tmp = helper(arr, n, j, x - arr[j], dp);
     ll tmp2 = helper(arr, n, j + 1, x, dp);
     ans = (ans % M + tmp % M) % M;
     ans = (ans % M + tmp2 % M) % M;
     // cout << j << " " << x << " " << ans << endl;
     dp[j][x] = ans + 1;
     // cout << j << " " << x << " " << ans << endl;
     return ans;
}
void solve()
{
     ll n, x;
     cin >> n >> x;
     vll arr(n);
     loop(0, n)
     {
          cin >> arr[i];
     }
     sort(arr.begin(), arr.end());

     // vector<unordered_map<int, ll>> dp(n + 1);
     vector<ll>dp(x+1,0);
     // ll ans = helper(arr, n, 0, x, dp);
     // cout << ans << endl;
     ll ans=0;
     for(int i=n-1;i>=0;i--){
          for(int j=arr[i];j<=x;j++){
               dp[j]=m
          }
     }
}

int main()
{
     int t;
     // cin >> t;
     t = 1;
     for (int j = 0; j < t; j++)
     {
          solve();
     }
     return 0;
}