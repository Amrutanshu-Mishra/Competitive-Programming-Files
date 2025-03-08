#include <bits/stdc++.h>
using namespace std;

//Tree Distances I
vector<int> graph[200001];
int fir[200001], sec[200001], ans[200001];

void dfs1(int node = 1, int parent = 0) {
	for (int i : graph[node])
		if (i != parent) {
			dfs1(i, node);
			if (fir[i] + 1 > fir[node]) {
				sec[node] = fir[node];
				fir[node] = fir[i] + 1;
			} else if (fir[i] + 1 > sec[node]) {
				sec[node] = fir[i] + 1;
			}
		}
}

void dfs2(int node = 1, int parent = 0, int to_p = 0) {
	ans[node] = max(to_p, fir[node]);
	for (int i : graph[node])
		if (i != parent) {
			if (fir[i] + 1 == fir[node]) dfs2(i, node, max(to_p, sec[node]) + 1);
			else dfs2(i, node, ans[node] + 1);
		}
}