#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, int i, vector<bool> &vis)
{
    if (vis[i])
    {
        return;
    }
    vis[i] = true;
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            dfs(adj, j, vis);
        }
    }
}

void solve(){
   
}  
int main(){ 
    int t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        solve();
    }
    return 0;
}