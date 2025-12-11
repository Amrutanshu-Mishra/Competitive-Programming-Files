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
int get_bit(ll n, ll pos)
{
    return (n & (1LL << pos)) != 0;
}
ll set_bit(ll n, int pos)
{
    n = n | (1 << pos);
    return n;
}
ll clear_bit(ll n, int pos)
{
    int ele = 1 << pos;
    ele = ~ele;
    n = n & ele;
    return n;
}
void update_bit(int &n, int pos, int value)
{
    int mark = ~(1 << pos);
    n = n & mark;
    n = n | (value << pos);
}
ll gcd(ll a, ll b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    ll ele = a * b;
    ll ele1 = gcd(a, b);
    return ele / ele1;
}
ll binexp(ll a, ll b, ll m)
{
    ll result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}
ll modexp(ll a)
{
    return binexp(a, M - 2, M);
}
class segtree
{
    int segSize;
    vector<long long> operations;

public:
    segtree(int n)
    {
        segSize = 1;
        while (segSize < n)
        {
            segSize *= 2;
        }
        operations.assign(2 * segSize, 0LL);
    }

    // using build is more optimised then using setVal for the initialization
    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
            {
                operations[x] = a[lx];
            }
            return;
        }

        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        operations[x] = operations[2 * x + 1] + operations[2 * x + 2];
    }

    void build(vector<int> &a)
    {
        build(a, 0, 0, segSize);
    }

    void modify(int l, int r, ll v, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
        {
            return;
        }

        // if [lx,rx] is completely inside given segment [l,r]
        if (lx >= l && rx <= r)
        {
            operations[x] = max(v, operations[x]);
            return;
        }
        // cout<<lx<<" "<<rx<<endl;
        int m = (lx + rx) / 2;

        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
    }

    void modify(int l, int r, ll v)
    {
        modify(l, r, v, 0, 0, segSize);
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
        res=max(res, operations[x]);
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
            st.modify(l,r,v);
        }
        else
        {
            int i;
            cin >> i;
            cout<<st.get(i)<<endl;
        }
        // cout<<"he"<<endl;
    }
}
int main()
{
    int t=1;
    // cin >> t;
    for (int j = 0; j < t; j++)
    {
        solve();
    }
    return 0;
}