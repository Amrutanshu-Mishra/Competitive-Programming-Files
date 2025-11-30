#include <bits/stdc++.h>
using namespace std;

int dp[20][2];

int helper(string &s, int idx, int tight){
     if(idx == s.size()){
          return 1;
     }

     if(dp[idx][tight]!=-1){
          return dp[idx][tight];
     }

     int limit = (tight == 1) ? s[idx]-'0' : 9;

     int ans=0;

     for(int i=0; i<=limit; i++){
          // int updatedCnt = cnt + (i==3);
          ans+=helper(s, idx+1, (tight && (i==s[idx]-'0')));
     }

     return dp[idx][tight]=ans;
}

void solve()
{
     int n;
     cin >> n;
     
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