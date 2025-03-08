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
void floydWarshall(vector<vector<int>> &graph) {
     int V = graph.size();
 
     // Add all vertices one by one to
     // the set of intermediate vertices.
     for (int k = 0; k < V; k++) {
 
         // Pick all vertices as source one by one
         for (int i = 0; i < V; i++) {
 
             // Pick all vertices as destination
             // for the above picked source
             for (int j = 0; j < V; j++) {
 
                 // If vertex k is on the shortest path from
                 // i to j, then update the value of graph[i][j]
 
                 if ((graph[i][j] == -1 || 
                     graph[i][j] > (graph[i][k] + graph[k][j]))
                     && (graph[k][j] != -1 && graph[i][k] != -1))
                     graph[i][j] = graph[i][k] + graph[k][j];
             }
         }
     }
 }