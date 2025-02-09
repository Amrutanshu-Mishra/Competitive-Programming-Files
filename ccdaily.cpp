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
     string a,b;
     cin>>a>>b;
     if(a.size()<b.size()){
          cout<<-1<<endl;
          return;
     }

     int i=a.size()-1;
     int j=b.size()-1;
     vector<bool>to_del(i+1,true);
     while (i>=0&&j>=0)
     {
          if(a[i]==b[j]){
               to_del[i]=false;
               i--;
               j--;
               
          }
          else{
               i--;
          }
     }
     if(j!=-1){
          cout<<-1<<endl;
          return;
     }
     // loop(0,to_del.size()){
     //      cout<<to_del[i]<<" ";
     // }
     // cout<<endl;
     i=0;
     ll ans=0;
     int curr=0;
     
     while(i<to_del.size()){
          if(to_del[i]==false){
               i++;
          }
          else{
               ans+=1LL*(i+1-curr);
               curr++;
               i++;
          }
     }
     cout<<ans<<endl;
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