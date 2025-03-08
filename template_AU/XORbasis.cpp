// An XOR basis is a minimal set of linearly independent binary vectors that can represent any vector in a given set through XOR combinations. In computational problems, constructing an XOR basis involves iteratively adding vectors to the basis while ensuring each new vector remains independent by reducing it with existing basis vectors. This basis allows efficient representation and manipulation of binary vector spaces, enabling quick determination of linear independence and facilitating solutions to various optimization and combinatorial problems.

// XOR basis involves two parts:


// Represent each given number in its base 2 form, considering it as a vector in the ${\mathbb{Z_2^d}}$ vector space, where $d$ is the maximum possible number of bits. The XOR operation on these numbers is equivalent to the addition of the corresponding vectors in the vector space ${\mathbb{Z_2^d}}$.


// Relate the answers to the queries of the second type with the basis of the vectors found in Part 1.



// By constructing an XOR basis from the set of vectors, we can efficiently answer various queries about linear independence, redundancy, and other properties related to the XOR combinations of the given numbers. This basis provides a compact representation that allows for quick computation and manipulation of the vector space.

#include <bits/stdc++.h>
using namespace std;

const int N = 200001, K = 20;
vector<int> arr(N), tin(N, 0), tout(N, 0), up[N];
vector<int> adj[N];
vector<vector<int>> p(N, vector<int>(K, 0));
int T = 0;

int reduce(array<int, K> &b, int x) {  // reducing x using basis vectors b
	for (int i = K - 1; i >= 0; i--) {
		if (x & (1 << i)) {  // check if the ith bit is set
			x ^= b[i];
		}
	}
	return x;
}

bool add(array<int, K> &b, int x) {
	x = reduce(b, x);  // reduce x using current basis
	if (x != 0) {
		for (int i = K - 1; i >= 0; i--) {
			if (x & (1 << i)) {
				b[i] = x;  // add x to the basis if it is independent
				return true;
			}
		}
	}
	return false;
}

bool check(array<int, K> &b, int x) {
	return (reduce(b, x) ==
	        0);  // if x reduces to 0, it can be represented by the basis
}

vector<int> rebuild_path(const vector<int> &path, int v) {
	array<int, K> b{0};
	vector<int> res;
	if (add(b, arr[v])) {
		res.push_back(v);  // add v to the result if it is independent
	}
	for (auto x : path) {
		if (add(b, arr[x])) {
			res.push_back(x);  // add x to the result if it is independent
		}
	}
	return res;
}

// Depth First Search to set up LCA and basis paths
void dfs(int v, int u) {
	tin[v] = T++;  // set in-time for the current node
	if (u == v) {
		up[v] = rebuild_path(vector<int>(0), v);  // root node case
	} else {
		up[v] = rebuild_path(up[u], v);  // rebuild path for the current node
	}

	p[v][0] = u;  // set direct path in ancestor table
	for (int i = 1; i < K; i++) {
		p[v][i] = p[p[v][i - 1]][i - 1];  // fill ancestor table for LCA
	}

	for (int i = 0; i < (int)adj[v].size(); i++) {
		if (adj[v][i] != u) {
			dfs(adj[v][i], v);  // recursively call dfs for children
		}
	}
	tout[v] = T++;  // set out-time for the current node
}

bool is_ancestor(int u, int v) {
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);  // check if u is an ancestor of v
}

int LCA(int x, int y) {
	if (is_ancestor(x, y)) {
		return x;  // return x if it is an ancestor of y
	}
	for (int i = K - 1; i >= 0; i--) {
		if (!is_ancestor(p[x][i], y)) {
			x = p[x][i];  // move x up in the tree
		}
	}
	return p[x][0];  // return the parent of x as the LCA
}

bool query(int x, int y, int k) {
	array<int, K> b{0};
	int lca = LCA(x, y);
	for (auto v : up[x]) {
		if (!is_ancestor(v, y)) {
			add(b, arr[v]);  // add vector to basis if not an ancestor of y
		}
	}

	for (auto v : up[y]) {
		if (!is_ancestor(v, x)) {
			add(b, arr[v]);  // Add vector to basis if not an ancestor of x
		}
	}

	add(b, arr[lca]);    // add LCA's value to basis
	return check(b, k);  // // check if k can be represented by the basis
}