#include <bits/stdc++.h>
using namespace std;

// Function to solve each test case
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // If all characters are already the same, transformation is impossible
    if (count(s.begin(), s.end(), s[0]) == n) {
        cout << -1 << endl;
        return;
    }

    int ans = 0;

    // Loop until the string becomes uniform (all same characters)
    while (true) {
        // Check if the string has become uniform
        if (count(s.begin(), s.end(), s[0]) == n) {
            break;
        }

        // Make a copy of the current string for reference
        string temp = s;

        // Traverse the string and apply transformation rules
        for (int i = 1; i < n - 1; i++) {
            // Check if both neighbors are the same but current is different
            if (temp[i - 1] == temp[i + 1] && temp[i] != temp[i - 1]) {
                s[i] = temp[i - 1]; // Flip the middle character
            }
        }

        ans++; // Count the number of operations
    }

    // Output the number of operations required
    cout << ans << endl;
}

// Main function to run multiple test cases
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
