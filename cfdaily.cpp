#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;


void solve() {
    int n; cin >> n;
    vecin(gears, n);
    set<int> seen;
    for (auto gear : gears) {
        if (seen.count(gear)) {
            cout << "YES" << endl; return;
        }
        seen.insert(gear);
    }
    cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;

    cin >> tt;

    while (tt--) solve();
    return 0;
}