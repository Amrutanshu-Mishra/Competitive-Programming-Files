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
class DisjointSet
{
     vector<int> size, parent;

public:
     DisjointSet(int n)
     {
          size.resize(n + 1, 1);
          parent.resize(n + 1);
          for(int i=0; i<n + 1;i++)
          {
               parent[i] = i;
          }
     }
     int findUPar(int node)
     {
          if (node == parent[node])
          {
               return node;
          }
          return parent[node] = findUPar(parent[node]);
     }
     void unionBySize(int u, int v)
     {
          int ulp_u = findUPar(u);
          int ulp_v = findUPar(v);
          if (ulp_u == ulp_v)
          {
               return;
          }
          if (size[ulp_u] < size[ulp_v])
          {
               size[ulp_v] += size[ulp_u];
               parent[ulp_u] = ulp_v;
               return;
          }
          size[ulp_u] += size[ulp_v];
          parent[ulp_u] = ulp_v;
     }
};

int main()
{
     DisjointSet ds(7);
     ds.unionBySize(1, 2);
     ds.unionBySize(2, 3);
     ds.unionBySize(4, 5);
     ds.unionBySize(6, 7);
     ds.unionBySize(5, 6);
     if (ds.findUPar(3) == ds.findUPar(7))
     {
          cout << "Same\n";
     }
     else
     {
          cout << "Not Same\n";
     }
     ds.unionBySize(3, 7);
     if (ds.findUPar(3) == ds.findUPar(7))
     {
          cout << "Same\n";
     }
     else
     {
          cout << "Not Same\n";
     }
}