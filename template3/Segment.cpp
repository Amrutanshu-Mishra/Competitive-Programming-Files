#include <bits/stdc++.h>
using namespace std;

template <class T> class SumSegmentTree {
  private:
	const T DEFAULT = 0;

	int len;
	vector<T> segtree;

	T combine(const T &a, const T &b) { return a + b; }

	void build(const vector<T> &arr, int at, int at_left, int at_right) {
		if (at_left == at_right) {
			segtree[at] = arr[at_left];
			return;
		}
		int mid = (at_left + at_right) / 2;
		build(arr, 2 * at, at_left, mid);
		build(arr, 2 * at + 1, mid + 1, at_right);
		segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
	}

	void set(int ind, T val, int at, int at_left, int at_right) {
		if (at_left == at_right) {
			segtree[at] = val;
			return;
		}
		int mid = (at_left + at_right) / 2;
		if (ind <= mid) {
			set(ind, val, 2 * at, at_left, mid);
		} else {
			set(ind, val, 2 * at + 1, mid + 1, at_right);
		}
		segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
	}

	T range_sum(int start, int end, int at, int at_left, int at_right) {
		if (at_right < start || end < at_left) { return DEFAULT; }
		if (start <= at_left && at_right <= end) { return segtree[at]; }
		int mid = (at_left + at_right) / 2;
		T left_res = range_sum(start, end, 2 * at, at_left, mid);
		T right_res = range_sum(start, end, 2 * at + 1, mid + 1, at_right);
		return combine(left_res, right_res);
	}

	int walk(int at, int at_left, int at_right, int max_val, int pref_res) {
		if (at_left == at_right) { return at_left; }
		int mid = (at_left + at_right) / 2;
		int sum_left = pref_res + segtree[2 * at];
		if (sum_left >= max_val) {
			return walk(2 * at, at_left, mid, max_val, pref_res);
		}
		return walk(2 * at + 1, mid + 1, at_right, max_val, sum_left);
	}

  public:
	SumSegmentTree(int len) : len(len) { segtree = vector<T>(len * 4, DEFAULT); };

	SumSegmentTree(const vector<T> &arr) : len(arr.size()) {
		segtree = vector<T>(len * 4, DEFAULT);
		build(arr, 1, 0, len - 1);
	}

	void set(int ind, T val) { set(ind, val, 1, 0, len - 1); }

	T range_sum(int start, int end) { return range_sum(start, end, 1, 0, len - 1); }

	/** @return first i such that the prefix sum up to i >= val */
	int walk(int val) { return walk(1, 0, len - 1, val, 0); }
};

// cin >> n;  // Read the number of elements
// for (int i = 1; i <= n; i++) cin >> a[i];  // Read the array
// build();  // Build the segment tree

// int q;
// cin >> q;  // Number of queries
// while (q--) {
//     int val;
//     cin >> val;
//     if (segtree[1] < val) cout << "0 ";  // If no element >= val, print 0
//     else queryupdate(val);  // Otherwise, process query
// }
// cout << endl;
