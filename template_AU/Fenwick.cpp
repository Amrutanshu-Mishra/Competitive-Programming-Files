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

// implementation of fenwick tree in O(NlogN)
struct FenwickTree
{
     vector<int> bit; // binary indexed tree
     int n;

     FenwickTree(int n)
     {
          this->n = n;
          bit.assign(n, 0);
     }

     FenwickTree(vector<int> const &a) : FenwickTree(a.size())
     {
          for (size_t i = 0; i < a.size(); i++)
               add(i, a[i]);
     }

     int sum(int r)
     {
          int ret = 0;
          for (; r >= 0; r = (r & (r + 1)) - 1)
               ret += bit[r];
          return ret;
     }

     int sum(int l, int r)
     {
          return sum(r) - sum(l - 1);
     }

     void add(int idx, int delta)
     {
          for (; idx < n; idx = idx | (idx + 1))
               bit[idx] += delta;
     }
};

// //implementation of fenwick tree in O(NlogN)
// FenwickTree(vector<int> const &a) : FenwickTree(a.size()){
//      for (int i = 0; i < n; i++) {
//          bit[i] += a[i];
//          int r = i | (i + 1);
//          if (r < n) bit[r] += bit[i];
//      }
//  }

// Finding minimum of [0, r]  in one-dimensional array
struct FenwickTreeMin
{
     vector<int> bit;
     int n;
     const int INF = (int)1e9;

     FenwickTreeMin(int n)
     {
          this->n = n;
          bit.assign(n, INF);
     }

     FenwickTreeMin(vector<int> a) : FenwickTreeMin(a.size())
     {
          for (size_t i = 0; i < a.size(); i++)
               update(i, a[i]);
     }

     int getmin(int r)
     {
          int ret = INF;
          for (; r >= 0; r = (r & (r + 1)) - 1)
               ret = min(ret, bit[r]);
          return ret;
     }

     void update(int idx, int val)
     {
          for (; idx < n; idx = idx | (idx + 1))
               bit[idx] = min(bit[idx], val);
     }
};

// Finding sum in two-dimensional array
struct FenwickTree2D
{
     vector<vector<int>> bit;
     int n, m;

     // init(...) { ... }

     int sum(int x, int y)
     {
          int ret = 0;
          for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
               for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                    ret += bit[i][j];
          return ret;
     }

     void add(int x, int y, int delta)
     {
          for (int i = x; i < n; i = i | (i + 1))
               for (int j = y; j < m; j = j | (j + 1))
                    bit[i][j] += delta;
     }
};

// one based indexing
struct FenwickTreeOneBasedIndexing
{
     vector<int> bit; // binary indexed tree
     int n;

     FenwickTreeOneBasedIndexing(int n)
     {
          this->n = n + 1;
          bit.assign(n + 1, 0);
     }

     FenwickTreeOneBasedIndexing(vector<int> a)
         : FenwickTreeOneBasedIndexing(a.size())
     {
          for (size_t i = 0; i < a.size(); i++)
               add(i, a[i]);
     }

     int sum(int idx)
     {
          int ret = 0;
          for (++idx; idx > 0; idx -= idx & -idx)
               ret += bit[idx];
          return ret;
     }

     int sum(int l, int r)
     {
          return sum(r) - sum(l - 1);
     }

     void add(int idx, int delta)
     {
          for (++idx; idx < n; idx += idx & -idx)
               bit[idx] += delta;
     }
     // Range Update and Point Query
     void add(int idx, int val)
     {
          for (++idx; idx < n; idx += idx & -idx)
               bit[idx] += val;
     }

     void range_add(int l, int r, int val)
     {
          add(l, val);
          add(r + 1, -val);
     }

     int point_query(int idx)
     {
          int ret = 0;
          for (++idx; idx > 0; idx -= idx & -idx)
               ret += bit[idx];
          return ret;
     }
};
