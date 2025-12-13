#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9 + 7;

class segtree
{
public:
     int segSize;
     vector<long long> operations;
     vector<long long> values;

     long long NO_OPERATION = LLONG_MAX - 1;
     long long NEUTRAL_ELEMENT = 0;

     // define the operation here like add or max or anything else
     //  this segtree is for commutative operations
     long long modify_op(long long a, long long b, long long len)
     {
          if (b == NO_OPERATION)
          {
               return a;
          }
          return b * len;
     }

     long long calc_op(long long a, long long b)
     {
          return a + b;
     }

     void apply_modify_op(long long &a, long long b, long long len)
     {
          a = modify_op(a, b, len);
     }

     void apply_calc_op(long long &a, long long b)
     {
          a = calc_op(a, b);
     }

     /*Use build whenever needed*/
     // void build(int x, int lx, int rx){
     //      if(rx-lx==1){
     //           values[x]=1;
     //           return;
     //      }
     //      int m=(lx+rx)/2;
     //      build(2*x+1, lx, m);
     //      build(2*x+2, m, rx);

     //      values[x] = calc_op(values[2*x+1], values[2*x+2]);
     // }

     segtree(int n)
     {
          segSize = 1;
          while (segSize < n)
          {
               segSize *= 2;
          }
          operations.assign(2 * segSize, NO_OPERATION);
          values.assign(2 * segSize, 0LL);
          // build(0,0,segSize);
     }

     void propagate(int x, int lx, int rx)
     {
          if (rx - lx == 1)
          {
               return;
          }

          int m = (lx + rx) / 2;
          apply_modify_op(values[2 * x + 1], operations[x], m - lx);
          apply_modify_op(operations[2 * x + 1], operations[x], 1);
          apply_modify_op(values[2 * x + 2], operations[x], rx - m);
          apply_modify_op(operations[2 * x + 2], operations[x], 1);
          operations[x] = NO_OPERATION;
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
               operations[x] = modify_op(operations[x], v, 1);
               values[x] = modify_op(values[x], v, rx - lx);
               return;
          }
          // cout<<lx<<" "<<rx<<endl;
          int m = (lx + rx) / 2;

          modify(l, r, v, 2 * x + 1, lx, m);
          modify(l, r, v, 2 * x + 2, m, rx);

          values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
     }

     void modify(int l, int r, long long v)
     {
          modify(l, r, v, 0, 0, segSize);
     }

     long long calc(int l, int r, int x, int lx, int rx)
     {
          propagate(x, lx, rx);
          if (lx >= r || rx <= l)
          {
               return NEUTRAL_ELEMENT;
          }

          if (lx >= l && rx <= r)
          {
               return values[x];
          }

          int m = (lx + rx) / 2;

          long long m1 = calc(l, r, 2 * x + 1, lx, m);
          long long m2 = calc(l, r, 2 * x + 2, m, rx);

          auto res = calc_op(m1, m2);

          return res;
     }

     long long calc(int l, int r)
     {
          return calc(l, r, 0, 0, segSize);
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
               int l, r;
               cin >> l >> r;
               cout << st.calc(l, r) << endl;
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