#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> w(n * n, 0);

    for (int i = 0; i < n * n; i++) {
        cin >> w[i];
    }

    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; v++) {
            if (w[u * n + v] != -1 && dist[u] + w[u * n + v] < dist[v]) {
                dist[v] = dist[u] + w[u * n + v];
                pq.push({dist[v], v});
            }
        }
    }

    int maxD = 0;
    
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "-1";
            return 0;
        }
        maxD = max(maxD, dist[i]);
    }

    cout << maxD << endl;
}

