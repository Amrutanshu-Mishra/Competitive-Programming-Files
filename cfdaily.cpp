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

int spf[500010];

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
     ll ans1=INT32_MAX;
     
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
          // if(i==1){
          //      cout<<a<<" j\n";
          // }
          while(a>1){
               // if(i==1){
               //      cout<<spf[a]<<endl;
               // }
               if(st.find(spf[a])!=st.end()){
                    ans1=min(ans1, b[i]);
                    // if(i==1){
                    //      cout<<b[i]<<" H "<<ans1<<endl;
                    // }
               }
     
               a/=spf[a];
          }
          // cout<<endl;
          for(auto p:curr){
               m1[p]+=m2[p];
               st.insert(p);
          }
     }     
     // cout<<endl;
     // if(ans1==INT32_MAX){
     //      cout<<"Yes"<<endl;
     // }
     ll ub1=INT64_MIN;
     vector<pair<ll,ll>>v;
     loop(0,n){
          v.push_back({b[i], arr[i]});
          ub1=max(ub1,arr[i]);
     }
     sort(v.begin(), v.end());
     ans1=min(ans1,v[0].first+v[1].first);
     // cout<<ans1<<endl;
     
     
     set<ll>curr;
     map<ll,int>m2;
     ll a=v[0].second;
     while (a>1)
     {
          m1[spf[a]]--;
          m2[spf[a]]++;
          curr.insert(spf[a]);
          if(m1[spf[a]]==0){
               st.erase(spf[a]);
          }
          a/=spf[a];
     }
     // for(auto i:st){
     //      cout<<i<<" ";
     // }
     // cout<<endl;
     // cout<<v[0].second+2*ub1-v[0].second<<endl;
     // cout<<ans1<<endl;
     // cout<<"H"<<endl;
     // cout<<ub1<<endl;
     if(st.size()==0){
          cout<<ans1<<endl;
          return;
     }

     ll p1=*st.begin();
     for(auto p2:curr){
          if(st.find(p2)!=st.end()){
               
          }
     }
     ans1=min(ans1, ((p1-(v[0].second%p1))%p1)*v[0].first);
     cout<<ans1<<endl;
}
int main()
{
     int t = 1;
     cin >> t;

     for(int i=0;i<500010;i++){
          spf[i]=i;
     }

     for(int i=2;i*i<500010;i++){
          if(spf[i]==i){
               for(int j=i*i;j<500010;j+=i){
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