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

// ll helper(int l,int r,int curr,int final){
//      if(l>=r){
//           return 1;
//      }
//      if(l==r-1){
//           if(abs(curr-final)<=1){
//                return 1;
//           }
//           return 0;
//      }
//      ll pos1=helper(l+1,r,curr,final);
//      ll pos2=0;
//      ll pos3=0;
//      if(curr<m){
//           pos2=helper(l+1,r,curr+1,final);
//      }
//      if(curr>0){
//           pos3=helper(l+1,r,curr-1,final);
//      }
//      dp[l][curr]=((pos1%M+pos2%M)%M+pos3%M)%M;
//      return dp[l][curr];
// }

void helper(string curr, int n, vector<string> &v)
{
    if (n == 0)
    {
        v.push_back(curr);
        return;
    }
    helper(curr + "0", n - 1, v);
    helper(curr + "1", n - 1, v);
}
int get_bit(ll n, ll pos)
{
    return (n & (1LL << pos)) != 0;
}
ll set_bit(ll n, int pos)
{
    n = n | (1 << pos);
    return n;
}
void solve()
{
    int n;
    cin>>n;
    vector<pair<ll,ll>>v;
    loop(0,n){
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    vector<set<double>>slo1(n);
    vector<set<double>>slo2(n);
    int count=0;
    for(int i=0;i<n;i++){
        
        for(int j=i+1;j<n;j++){
            double num=v[j].second-v[i].second;
            double denom=v[j].first-v[i].first;
            // cout<<num<<" "<<denom<<endl;
            double pr=denom;
            if(num!=0){
                pr=pr*num;
            }
            if(denom==0){
                pr=num;
            }
            if(abs(denom)<=1e-11){
                if(pr>=0){
                    // cout<<1e18<<" ";
                    if(slo1[i].find(1e18)==slo1[i].end()&&slo2[j].find(1e18)==slo2[j].end()){
                        // cout<<i<<endl;
                        
                        slo1[i].insert(1e18);
                        slo2[j].insert(1e18);
                        count++;
                    }
                }
                else{
                    if(slo1[i].find(-1e18)==slo1[i].end()&&slo2[j].find(-1e18)==slo2[j].end()){
                        // cout<<i<<endl;
                        
                        slo1[i].insert(-1e18);
                        slo2[j].insert(-1e18);
                        count++;
                    }
                }
                continue;
            }
            double sl=(num/denom);
            // cout<<sl<<" ";
            
            
                
            if(slo1[i].find(sl)==slo1[i].end()&&slo2[j].find(sl)==slo2[j].end()){
                count++;
                slo1[i].insert(sl);
                slo2[j].insert(sl);
            }
            
        }
        // cout<<endl;
        // cout<<count<<endl;
    }
    cout<<count<<endl;
}

int main()
{
    int t;
    t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    
}
