#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define F first
#define S second
//#define um unordered_map
#define us unordered_set
//#define endl '\n';
typedef vector<int> vi;
typedef long long ll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;

typedef pair<int,int> ii;
typedef vector<pair<int,int>> vii;
typedef vector<pair<ll,ll>> vpl;
typedef pair<ll,ll> pll;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less_equal<int>,rb_tree_tag,
//         tree_order_statistics_node_update> indexed_set;

//s.find_by_order(i)--for it of position i
//*it = s[i]
//s.order_of_key(ele)--for lower bound index (0-based) of target
//s.lower_bound(ele)--for iterator of lower bound of target
//Note that using first and second both nested costs (Log^2)(n)

ll mod1=1000000007;
ll mod2=998244353;
int inf = 1e9;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int l = 0;
    int r = n-1;
    vvi ind(n+1);
    for(int i=0;i<n;i++) ind[a[i]].push_back(i);

    vi ans(n,0);
    for(int i=1;i<=n-1;i++){
        if(ind[i].empty()) break;
        if(ind[i].size() > 1 || ind[i][0] != l && ind[i][0] != r){
            ans[n-i] = 1;
            break;
        }
        if(ind[i][0] == l) l++;
        else r--;
        ans[n-i] = 1;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i] != i+1){
            for(int j: ans) cout<<j;
            cout<<endl;
            return;
        }
    }
    ans[0] = 1;
    for(int j: ans) cout<<j;
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t=1;
    cin>>t;
    while(t-->0) solve();
}