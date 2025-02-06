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

int helper(string &s1, string s2)
{
     int count = 0;
     string s3 = "";
     for (int i = 0; i < s1.size(); i += 3)
     {
          s3 = "";
          for (int j = i; j < i + 3; j++)
          {
               if (j == s1.size())
               {
                    break;
               }
               s3 += s1[j];
          }
          int a = 0;
          int b = 0;
          while (a < s3.size())
          {
               if (s3[a] != s2[b])
               {
                    count++;
               }
               a++;
               b++;
          }
     }
     return count;
}

void solve()
{
     ll n, p;
     cin >> n >> p;
     vll arr(n);
     loop(0, n)
     {
          cin >> arr[i];
     }
     vi rv(n, 0);
     vi lv(n, 0);
     vll rm(n, 0);
     vll lm(n, 0);
     int tmp = -1;
     for (int i = n - 1; i >= 0; i--)
     {
          if (arr[i] == 0)
          {
               tmp = i;
          }
          rv[i] = tmp;
     }
     tmp = -1;
     loop(0, n)
     {
          if (arr[i] == 0)
          {
               tmp = i;
          }
          lv[i] = tmp;
     }
     ll h1 = 0;
     for (int i = n - 1; i >= 0; i--)
     {
          if (arr[i] == 0)
          {
               h1 = 0;
          }
          h1 = max(h1, arr[i]);
          rm[i] = h1;
     }
     h1 = 0;
     for (int i = 0; i < n; i++)
     {
          if (arr[i] == 0)
          {
               h1 = 0;
          }
          h1 = max(h1, arr[i]);
          lm[i] = h1;
     }
     vll ans(n, 0);
     loop(0, n)
     {
          ll lt = INT64_MAX;
          ll rt = INT64_MAX;
          if (lv[i] != -1)
          {
               lt = lm[i] / p + (lm[i] % p != 0);
          }
          if (rv[i] != -1)
          {
               rt = rm[i] / p + (rm[i] % p != 0);
          }
          ans[i] = min(lt, rt);
     }
     loop(0, n)
     {
          cout << ans[i] << " ";
     }
     cout << endl;
}
int main()
{
     int t;
     t = 1;
     cin >> t;

     for (int j = 0; j < t; j++)
     {
          solve();
     }
     return 0;
}