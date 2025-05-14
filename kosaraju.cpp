//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(vector<vector<int>> &adj,int node,vector<bool>&vis,stack<int>&st){
        vis[node]=true;
        for(auto adjNode:adj[node]){
            if(!vis[adjNode]){
                dfs(adj,adjNode,vis,st);
            }
        }
        st.push(node);
    }
    void dfs3(vector<vector<int>> &adjT,int node,vector<bool>&vis){
        vis[node]=true;
        for(auto adjNode:adjT[node]){
            if(!vis[adjNode]){
                dfs3(adjT,adjNode,vis);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<bool>vis(n,false);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis,st);
            }
        }
        vector<vector<int>>adjT(n);
        for(int i=0;i<n;i++){
            vis[i]=false;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        int scc=0;
        while(!st.empty()){
            int i=st.top();
            st.pop();
            if(!vis[i]){
                scc++;
                dfs3(adjT,i,vis);
            }
        }
        return scc;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends