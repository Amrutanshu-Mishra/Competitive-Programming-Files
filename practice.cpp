//dijkstra, bellmen ford , floyd warshall's , mst, kosaraju, DSU 
#include<iostream>
#include<stack>
#include<vector>
#include<set>
using namespace std;

vector<int> dijkstra_algo(vector<vector<vector<int>>>&adj,int n, int src){
    vector<int>ans(n,INT32_MAX);
    ans[src]=0;
    set<pair<int,int>>st;
    st.insert({0,src});
    while(st.size()>0){
        pair<int,int>p=*st.begin();
        st.erase(p);
        int node=p.second;
        int dis=p.first;
        for(auto i:adj[node]){
            int adjNode=i[1];
            int edgeW=i[0];
            if(dis+edgeW<ans[adjNode]){
                if(ans[adjNode]!=INT32_MAX){
                    st.erase({ans[adjNode],adjNode});
                }
                ans[adjNode]=dis+edgeW;
                st.insert({ans[adjNode],adjNode});
            }
        }
        
    }
    return ans;
}

vector<vector<int>> floyd_algo(vector<vector<int>>&adj,int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]>adj[i][k]+adj[k][j]){
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }
    return adj;
}

vector<int> bellman_algo(vector<vector<int>>&edges,int src,int n){
    vector<int>ans(n,1e7);
    ans[src]=0;
    for (int i = 0; i < n-1; i++)
    {
        for(auto edge:edges){
            int a=edge[0];
            int b=edge[1];
            int edgeW=edge[2];
            if(ans[a]<1e7 && ans[a]+edgeW<ans[b]){
                ans[b]=ans[a]+edgeW;
            }
        }
    }
    return ans;
}



int main(){

}