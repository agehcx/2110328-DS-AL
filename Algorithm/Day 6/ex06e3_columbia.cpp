#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

typedef pair<int, pair<int, int>> PIP;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c; cin >> r >> c;
    int arr[r][c], dist[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            dist[i][j] = INT_MAX;
        }
    }

    priority_queue<PIP, vector<PIP>, greater<PIP>> pq;
    pq.push({0, {0, 0}});
    
    dist[0][0] = 0;

    while (!pq.empty()) {
        auto [w, di] = pq.top();
        int dx = di.first, dy = di.second;
        pq.pop();

        if (dist[dx][dy] < w) continue;

        for (auto& [px, py] : dir) {
            int nx = dx + px, ny = dy + py;
            if (0 <= nx && nx < r && 0 <= ny && ny < c && w + arr[nx][ny] < dist[nx][ny]) {
                dist[nx][ny] = w + arr[nx][ny];
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << dist[i][j] << ' ';
        cout << '\n';
    }

}