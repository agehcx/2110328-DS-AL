#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> vec(503, vector<double>(503));

bool solve() {
    int N; cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> vec[i][j];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                vec[i][j] = max(vec[i][j], vec[i][k] * vec[k][j]);
                if (i == j && vec[i][j] > 1) return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q; cin >> Q;
    while (Q--) cout << (solve() ? "YES\n" : "NO\n");
}


