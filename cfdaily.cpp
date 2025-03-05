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
int n,m;
vector<vll>dp;
ll helper(int l,int r,int curr,int final){
     if(l>=r){
          return 1;
     }
     if(l==r-1){
          if(abs(curr-final)<=1){
               return 1;
          }
          return 0;
     }
     ll pos1=helper(l+1,r,curr,final);
     ll pos2=0;
     ll pos3=0;
     if(curr<m){
          pos2=helper(l+1,r,curr+1,final);
     }
     if(curr>0){
          pos3=helper(l+1,r,curr-1,final);
     }
     dp[l][curr]=((pos1+pos2)%M+pos3)%M;
     return dp[l][curr];
}
void solve()
{
     cin>>n>>m;
     dp=vector<vll>(n,vll(m+1,0));
     int arr[n];
     loop(0,n){
          cin>>arr[i];
     }
     int a=-1;
     loop(0,n){
          if(arr[i]==0){
               a=i;
          }
          else{
               break;
          }
     }
     ll ans=binexp(3,a+1,M);
     
     int b=n;
     for(int i=n-1;i>=0;i--){
          if(arr[i]==0){
               b=i;
          }
          else{
               break;
          }
     }
     ans=(ans*binexp(3,n-b,M))%M;
     // cout<<ans<<endl;
     // cout<<a<<" "<<b<<endl;
     int pre=a+1;
     // cout<<pre<<endl;
     loop(a+2,n){
          if(arr[i]!=0){
               // cout<<pre<<" "<<i<<endl;
               ll tmp=helper(pre,i,arr[pre],arr[i]);
               // cout<<tmp<<endl;
               ans=(ans*tmp)%M;
          }
     }
     
     cout<<ans<<endl;
}    
 
int main()
{
     int t;
     
     t=1;
     // cin >> t;
     for (int j = 0; j < t; j++)
     {
          solve();
     }
     return 0;
}
