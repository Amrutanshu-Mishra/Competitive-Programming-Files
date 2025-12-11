#include <bits/stdc++.h>
using namespace std;

class segtree
{
     int segSize;
     long long NO_OPERATION = LLONG_MAX;
     vector<long long> operations;

public:
     long long operation(long long a, long long b)
     {
          if (b == NO_OPERATION)
               return a;
          return b;
     }

     void apply_operations(long long &a, long long b)
     {
          a = operation(a, b);
     }

     segtree(int n)
     {
          segSize = 1;
          while (segSize < n)
          {
               segSize *= 2;
          }
          operations.assign(2 * segSize, 0LL);
     }

     void propagate(int x, int lx, int rx)
     {
          if (rx - lx == 1)
          {
               return;
          }

          apply_operations(operations[2 * x + 1], operations[x]);
          apply_operations(operations[2 * x + 2], operations[x]);

          operations[x]=NO_OPERATION;
     }

     void modify(int l, int r, long long v, int x, int lx, int rx)
     {
          propagate(x, lx, rx);
          if (lx >= r || l >= rx)
          {
               return;
          }

          // if [lx,rx] is completely inside given segment [l,r]
          if (lx >= l && rx <= r)
          {
               // operations[x] += v;
               apply_operations(operations[x], v);
               return;
          }
          int m = (lx + rx) / 2;

          modify(l, r, v, 2 * x + 1, lx, m);
          modify(l, r, v, 2 * x + 2, m, rx);
     }

     void modify(int l, int r, long long v)
     {
          modify(l, r, v, 0, 0, segSize);
     }

     long long get(int i, int x, int lx, int rx)
     {
          propagate(x, lx, rx);
          if (rx - lx == 1)
          {
               return operations[x];
          }

          int m = (lx + rx) / 2;

          long long res = 0;
          if (i < m)
          {
               res = get(i, 2 * x + 1, lx, m);
          }
          else
          {
               res = get(i, 2 * x + 2, m, rx);
          }
          return res;
     }

     long long get(int i)
     {
          return get(i, 0, 0, segSize);
     }
};

void solve()
{
     long long n, m;
     cin >> n >> m;

     segtree st(n);

     while (m--)
     {
          int op;
          cin >> op;
          if (op == 1)
          {
               int l, r;
               long long v;
               cin >> l >> r >> v;
               // cout<<"H "<<l<<" "<<r<<" "<<v<<endl;
               st.modify(l, r, v);
          }
          else
          {
               int i;
               cin >> i;
               cout << st.get(i) << endl;
          }
          // cout<<"he"<<endl;
     }
}
int main()
{
     int t = 1;
     // cin >> t;
     for (int j = 0; j < t; j++)
     {
          solve();
     }
     return 0;
}