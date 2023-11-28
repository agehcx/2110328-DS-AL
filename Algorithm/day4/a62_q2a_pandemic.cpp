#include <bits/stdc++.h>
using namespace std;

const int mxn = 505;

vector<vector<int>> vec(mxn, vector<int>(mxn, 0));
vector<vector<bool>> vis(mxn, vector<bool>(mxn, false));

queue<pair<int, int>> q;

int dix[4] = {0, -1, 0, 1};
int diy[4] = {1, 0, -1, 0};
int r, c, t;

int cnt = 0;

bool isValid(int dx, int dy) {
    return 0 <= dx && dx < r && 0 <= dy && dy < c && vec[dx][dy] == 0;
}

void dfs() {
    queue<pair<int, int>> tmp;
    while (!q.empty()) {
        auto& [f, s] = q.front();
        q.pop();

        if (vec[f][s] = 1) continue;
        vec[f][s] = 1;

        cnt++;

        tmp.push({f,s});

        for (int i = 0; i < 4; i++) {
            int nf = f + dix[i];
            int ns = s + diy[i];
            if (isValid(nf, ns)) {
                tmp.push({nf, ns});
            }
        }
    }
    q = tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> vec[i][j];
            if (vec[i][j] == 1) {
                q.push({i,j});
            }
        }
    }
    for (int i = 0; i < t + 1; i++) {
        dfs();
    }
    cout << cnt;
}