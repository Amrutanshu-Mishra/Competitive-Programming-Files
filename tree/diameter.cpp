#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N]; // defining the graph
int depth[N];

void dfs(int v, int par = -1)
{
     for (int child : g[v])
     {
          if (child != par)
          {
               depth[child] = depth[v] + 1;
               dfs(child, v);
          }
     }
}

void solve()
{
     int n;
     cin >> n;

     for (int i = 0; i < n - 1; i++)
     {
          int x, y;
          cin >> x >> y;

          g[x].push_back(y);
          g[y].push_back(x);
     }

     dfs(1);
     int max_depth = -1;
     int max_dep_node = -1;

     for (int i = 1; i <= n; i++)
     {
          if (max_depth < depth[i])
          {
               max_depth = depth[i];
               max_dep_node = i;
          }
          depth[i]=0;
     }

     dfs(max_dep_node);

     int node1=max_dep_node;
     max_dep_node=-1;
     max_depth=-1;

     for (int i = 1; i <= n; i++)
     {
          if (max_depth < depth[i])
          {
               max_depth = depth[i];
               max_dep_node = i;
          }
          depth[i]=0;
     }

     int node2=max_dep_node;
     int diameter=max_depth;

     cout<<"Diameter "<<diameter<<endl;
     cout<<"End points "<<node1<<" "<<node2<<endl;
}
int main()
{
     int t=1;
     // cin >> t;
     for (int j = 0; j < t; j++)
     {
          solve();
     }
     return 0;
}