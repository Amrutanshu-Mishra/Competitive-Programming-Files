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


vector<vector<pair<int, int>>> adj;
void dijkstra(int s, vector<int> & d, vector<int> & p) {
     int n = adj.size();
     d.assign(n, M);
     p.assign(n, -1);
     vector<bool> u(n, false);
 
     d[s] = 0;
     for (int i = 0; i < n; i++) {
         int v = -1;
         for (int j = 0; j < n; j++) {
             if (!u[j] && (v == -1 || d[j] < d[v]))
                 v = j;
         }
 
         if (d[v] == M)
             break;
 
         u[v] = true;
         for (auto edge : adj[v]) {
             int to = edge.first;
             int len = edge.second;
 
             if (d[v] + len < d[to]) {
                 d[to] = d[v] + len;
                 p[to] = v;
             }
         }
     }
 }