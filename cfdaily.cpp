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

int spf[200010];

void solve()
{
     int n;
     cin>>n;

     vll arr(n);
     loop(0,n){
          cin>>arr[i];
     }

     vll b(n);
     loop(0,n){
          cin>>b[i];
     }

     set<ll>st;
     map<ll,int>m1;
     loop(0,n){
          set<ll>curr;
          ll a=arr[i];
          while(a>1){
               if(st.find(spf[a])!=st.end()){
                    cout<<0<<endl;
                    return;
               }
               m1[spf[a]]++;
               curr.insert(spf[a]);
               a/=spf[a];
          }
          for(auto p:curr){
               // cout<<p<<" ";
               st.insert(p);
          }
     }
     
     // cout<<"J"<<endl;
     
     loop(0,n){
          set<ll>curr;
          map<ll,int>m2;
          
          ll a=arr[i];
          while(a>1){
               m1[spf[a]]--;
               m2[spf[a]]++;
               curr.insert(spf[a]);
               if(m1[spf[a]]==0){
                    st.erase(spf[a]);
               }
               a/=spf[a];
          }
          
          a=arr[i]+1;
          // cout<<"J"<<endl;
          while(a>1){
               // cout<<a<<" ";
               if(st.find(spf[a])!=st.end()){
                    // cout<<spf[a]<<endl;
                    cout<<1<<endl;
                    return;
               }
     
               a/=spf[a];
          }
          // cout<<endl;
          for(auto p:curr){
               m1[p]+=m2[p];
               st.insert(p);
          }
     }     
     cout<<2<<endl;
}
int main()
{
     int t = 1;
     cin >> t;

     for(int i=0;i<=200010;i++){
          spf[i]=i;
     }

     for(int i=2;i*i<=200010;i++){
          if(spf[i]==i){
               for(int j=i*i;j<=200010;j+=i){
                    if(spf[j]==j){
                         spf[j]=i;
                    }
               }
          }
     }
     // loop(0,50){
     //      cout<<spf[i]<<" ";
     // }
     // cout<<endl;
     for (int j = 0; j < t; j++)
     {
          solve();
     }
     return 0;
}