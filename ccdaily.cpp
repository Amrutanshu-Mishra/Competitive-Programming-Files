#include <bits/stdc++.h>
using namespace std;

int stallsVisited(vector<int> dist, vector<int> lit, int distance, int initEnergy) {
    int n = dist.size();
    vector<pair<int, int>> stalls;
    for (int i = 0; i < n; i++) stalls.push_back({dist[i], lit[i]});

    sort(stalls.begin(), stalls.end());
    priority_queue<int> pq; // max-heap for available juice

    int currEnergy = initEnergy;
    int i = 0, stops = 0;

    while (currEnergy < distance) {
        // Add all reachable stalls
        while (i < n && stalls[i].first <= currEnergy) {
            pq.push(stalls[i].second);
            i++;
        }

        // No reachable stall
        if (pq.empty()) return -1;

        // Drink from the best stall
        currEnergy += pq.top();
        pq.pop();
        stops++;
    }

    return stops;
}

int main() {
    int n;
    cin >> n;
    vector<int> dist(n);
    for (int i = 0; i < n; i++) cin >> dist[i];

    int m;
    cin >> m;
    vector<int> lit(m);
    for (int i = 0; i < m; i++) cin >> lit[i];

    int distance, initEnergy;
    cin >> distance >> initEnergy;

    cout << stallsVisited(dist, lit, distance, initEnergy);
    return 0;
}
