#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define loop(j,n) for(int i = j; i < n;i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ll> vll;

const int M=1e9+7;

class Solution {
    int timer=1;
    void dfs(int node,int parent,vector<bool>&vis,vector<vector<int>>&adj,vector<int>&tin,vector<int>&low,vector<vector<int>>&ans){
        vis[node]=true;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                //if not visited then we first recursively call this
                dfs(it,node,vis,adj,tin,low,ans);
                
                //then we update the current node's low value
                low[node]=min(low[node],low[it]);
                
                //checking for bridge
                if(low[it]>tin[node]){//if this if is satisfied this is a bridge
                    ans.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //making the adjacency list
        vector<vector<int>>adj(n);
        for(auto edge:connections){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>vis(n,false);
        vector<int>tin(n);
        vector<int>low(n);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,adj,tin,low,ans);
            }
        }
        
        return ans;
    }
};
void solve(){
   int n;
   cin>>n;
   vll arr(n);
   loop(0,n){
    cin>>arr[i];
   }
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
