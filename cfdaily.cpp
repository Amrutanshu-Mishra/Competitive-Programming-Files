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

ll dp[10][2][81];
unordered_map<int,bool>isP;

ll helper(string &s, int idx, int tight, int sum){
     if(idx==s.size()){
          return isP[sum];
     }
     // cout<<"J"<<endl;
     if(dp[idx][tight][sum]!=-1){
          return dp[idx][tight][sum];
     }

     int limit=tight ? (s[idx]-'0') : 9;
     ll ans=0;

     for(int i=0;i<=limit;i++){
          int updatedSum=sum+i;
          ans+=helper(s, idx+1, tight && (i==(s[idx]-'0')), updatedSum);
     }
     return dp[idx][tight][sum]=ans;
}

void solve()
{
     ll l,r;
     cin>>l>>r;

     string ri=to_string(r);
     memset(dp, -1, sizeof(dp));
     // cout<<"j"<<endl;
     ll ans1=helper(ri, 0, 1, 0);
     if(l==0){
          cout<<ans1<<endl;
          return;
     }

     string li=to_string(l-1);
     memset(dp, -1, sizeof(dp));
     ll ans2=helper(li, 0, 1, 0);

     cout<<ans1-ans2<<endl;
}
int main()
{
     int t=1;
     for(int i=2;i<=81;i++){
          bool prim=true;
          for(int j=2;j*j<=i;j++){
               if(i%j==0){
                    prim=false;
                    break;
               }
          }
          isP[i]=prim;
     }

     cin >> t;
     for (int j = 0; j < t; j++)
     {
          solve();
     }
     return 0;
}