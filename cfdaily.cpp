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
const int M = 1000000007;

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    int ma=0;
    
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        ma=max(ma,arr[i]);
    }
    vector<bool> present(ma+1,false);
    for(int i=0;i<n;i++){        
        present[arr[i]]=true;
    }

    vector<int> dp(ma + 1, 0);
    int ans = 0;
    for (int i = 1; i <= ma; i++)
    {
        if (!present[i])
        {
            continue;
        }
        dp[i] = max(dp[i], 1);
        ans = max(ans, dp[i]);
        for (int j = i * 2; j <= ma; j += i)
        {
            if(!present[j]){
                continue;
            }
            dp[j] = max(dp[j], 1 + dp[i]);
        }
    }
  
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
}