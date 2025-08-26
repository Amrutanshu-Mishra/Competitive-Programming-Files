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

void solve()
{
    int n;
    cin>>n;
    vll arr(n+1,0);
    loop(1,n+1){
        cin>>arr[i];
    }
    //dp1[i] represents the minimum number of balls that can't be deleted in prefix array [1...i]
    vll dp1(n+1,n+10);
    /*dp2[i] represents the minimum number of balls that can't be deleted in all possible prefix array [1...x]
    where arr[x]=i
    */
    vll dp2(n+1,n+10);
    dp1[0]=0;
    for(int i=1;i<=n;i++){
        dp1[i]=min(dp1[i-1]+1,dp2[arr[i]]);
        // if(dp1[dp2[arr[]]])
        dp2[arr[i]]=min(dp2[arr[i]],dp1[i-1]);
    }
    // loop(0,n+1){
    //     cout<<dp1[i]<<" ";
    // }
    // cout<<endl;
    cout<<n-dp1[n]<<endl;
}
int main()
{
    int t;
    t=1;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        solve();
    }
    return 0;
}