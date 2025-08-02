#include <bits/stdc++.h>
using namespace std;

// Helper to trim leading/trailing spaces
string trim(string str) {
    if (str.empty()) return str;
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Helper to split string by space
vector<string> splitstring(string input_string) {
    vector<string> splits;
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y && x == ' ';
    });
    input_string.erase(new_end, input_string.end());
    while (!input_string.empty() && input_string.back() == ' ') {
        input_string.pop_back();
    }
    stringstream ss(input_string);
    string word;
    while (ss >> word) {
        splits.push_back(word);
    }
    return splits;
}

// Main solving function
long long solve(int n, int m, const vector<vector<int>>& a) {
    map<int, vector<pair<int, int>>> buildings_by_type;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            buildings_by_type[a[i][j]].emplace_back(i, j);

    long long total_manhattan_distance = 0;

    for (const auto& [type, coords] : buildings_by_type) {
        if (coords.size() < 2) continue;

        vector<int> rows, cols;
        for (auto [x, y] : coords) {
            rows.push_back(x);
            cols.push_back(y);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        long long k = coords.size();
        long long row_sum = 0, col_sum = 0;

        for (long long i = 0; i < k; ++i) {
            row_sum += (2 * i - k + 1) * 1LL * rows[i];
            col_sum += (2 * i - k + 1) * 1LL * cols[i];
        }

        total_manhattan_distance += row_sum + col_sum;
    }

    return total_manhattan_distance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string inputline;
    getline(cin, inputline);
    int n = stoi(trim(inputline));

    getline(cin, inputline);
    int m = stoi(trim(inputline));

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        getline(cin, inputline);
        vector<string> parts = splitstring(trim(inputline));
        for (int j = 0; j < m; ++j) {
            a[i][j] = stoi(parts[j]);
        }
    }

    cout << solve(n, m, a) << "\n";
    return 0;
}
