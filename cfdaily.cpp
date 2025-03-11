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
ll clear_bit(ll n, int pos)
{
    int ele = 1 << pos;
    ele = ~ele;
    n = n & ele;
    return n;
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    long long x[n];
    loop(0,n){
        cin>>x[i];
    }
    long long r[n];
    ll rm=-1;
    loop(0,n){
        cin>>r[i];
        rm=max(rm,r[i]);
    }
    // vector<pair<ll,ll>>v;
    // loop(0,n){
    //     v.push_back({x[i],r[i]});
    // }
    // sort(v.begin(),v.end());
    // for(auto i:v){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    // cout<<endl;
    ll ans=0;
    vector<vector<pair<ll,ll>>>s(rm+1);

    for(int i=0;i<n;i++){
        for(int j=0;j<=r[i];j++){
            ll xmi=x[i]-sqrt(double(r[i]*r[i]-j*j));
            if(xmi!=x[i]-sqrt(double(r[i]*r[i]-j*j))&&x[i]-sqrt(double(r[i]*r[i]-j*j))>0){
                xmi++;
            }
            ll xma=x[i]+sqrtl(double(r[i]*r[i]-j*j));
            s[j].push_back({xmi,xma});
        }
    }
    
    loop(0,rm+1){
        stack<pair<ll,ll>>s1;
        sort(s[i].begin(),s[i].end());
        for(int j=0;j<s[i].size();j++){
            if(s1.empty()){
                s1.push(s[i][j]);
            }
            else{
                pair<ll,ll>p1=s1.top();
                s1.pop();
                if(s[i][j].first<=p1.second){
                    s1.push({min(p1.first,s[i][j].first),max(p1.second,s[i][j].second)});
                }
                else{
                    s1.push(p1);
                    s1.push(s[i][j]);
                }
            }
        }
        // cout<<i<<endl;
        while(s1.size()){
            pair<ll,ll>p1=s1.top();
            s1.pop();
            // cout<<p1.first<<" "<<p1.second<<endl;
            ans+=p1.second-p1.first+1;
            if(i!=0){
                ans+=p1.second-p1.first+1;
            }
        }
        // cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
}

int main()
{
    int t;
    t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
}
