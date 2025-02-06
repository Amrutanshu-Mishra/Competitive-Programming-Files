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


ll helper(vll &arr,int n,vector<string>&v,int i,int A,int B,int C,vector<vector<vector<vector<int>>>>&dp){
     if(i==n){
          if(A&&B&&C){
               return 0;
          }
          else{
               return 1e9;
          }
     }
     if(dp[i][A][B][C]!=-1){
          return dp[i][A][B][C];
     }
     ll take=arr[i];
     bool A1=A;
     bool B1=B;
     bool C1=C;
     for(auto j:v[i]){
          if(j=='A'){
               A1=1;
          }
          if(j=='B'){
               B1=1;
          }
          if(j=='C'){
               C1=1;
          }
     }
     take+=helper(arr,n,v,i+1,A1,B1,C1,dp);
     ll not_take=helper(arr,n,v,i+1,A,B,C,dp);
     ll ans=min(take,not_take);
     dp[i][A][B][C]=ans;
     return ans;
}
void solve()
{
     int n;
     cin >> n;
     vll arr(n);
     vector<string>v;
     vector<pair<ll,string>>b(n);
     loop(0, n)
     {
          ll a;
          cin>>b[i].first;
          cin>>b[i].second;
          // cout<<b[i].first<<" "<<b[i].second<<endl;
          arr[i]=b[i].first;
          v.push_back(b[i].second);
     }
     // loop(0,n){
     //      cout<<arr[i]<<" ";
     // }
     // cout<<endl;
     vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(2,vector<vector<int>>(2,vector<int>(2,-1))));
     ll ans=helper(arr,n,v,0,0,0,0,dp);
     if(ans>=1e9){
          ans=-1;
     }
     cout<<ans<<endl;
}
int main()
{
     int t;
     // cin >> t;
     t=1;
     for (int j = 0; j < t; j++)
     {
          solve();
     }
     return 0;
}