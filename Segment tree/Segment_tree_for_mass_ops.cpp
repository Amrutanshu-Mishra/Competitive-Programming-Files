#include <bits/stdc++.h>
using namespace std;

class segtree
{
     public:
     int segSize;
     vector<long long> operations;

     //define the operation here like add or max or anything else 
     // this segtree is for commutative operations
     long long operation(long long a, long long b){
          return max(a,b);
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

     void add(int l, int r, long long v, int x, int lx, int rx)
     {
          if (lx >= r || l >= rx)
          {
               return;
          }

          // if [lx,rx] is completely inside given segment [l,r]
          if (lx >= l && rx <= r)
          {
               operations[x] = operation(operations[x], v);
               return;
          }
          // cout<<lx<<" "<<rx<<endl;
          int m = (lx + rx) / 2;

          add(l, r, v, 2 * x + 1, lx, m);
          add(l, r, v, 2 * x + 2, m, rx);
     }

     void add(int l, int r, long long v)
     {
          add(l, r, v, 0, 0, segSize);
     }

     long long get(int i, int x, int lx, int rx)
     {

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
          return operation(operations[x] , res);
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
               st.add(l, r, v);
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