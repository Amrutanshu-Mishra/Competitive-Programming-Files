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

void solve()
{
    long long n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;

    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            pos = i;
            a[i] = -1e13;
        }
    }

    long long mx = 0;
    long long curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr = max(curr + a[i], a[i]);
        mx = max(mx, curr);
    }
    if (mx > k || (mx != k && pos == -1))
    {
        cout << "No\n";
        return;
    }
    if (pos != -1)
    {
        mx = 0, curr = 0;
        long long L, R;

        for (int i = pos + 1; i < n; i++)
        {
            curr += a[i];
            mx = max(mx, curr);
        }
        L = mx;
        mx = 0;
        curr = 0;
        for (int i = pos - 1; i >= 0; i--)
        {
            curr += a[i];
            mx = max(mx, curr);
        }
        R = mx;

        a[pos] = k - L - R;
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " \n"[i + 1 == n];
    }
}
int main()
{
    int t;
    t = 1;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        solve();
    }
    return 0;
}