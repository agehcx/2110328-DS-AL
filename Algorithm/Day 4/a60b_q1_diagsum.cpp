#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int v[n][n] = {0};
    vector<int> ss[2 * n - 1];
    int mxn = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            mxn = max(mxn, v[i][j]);
            ss[i - j + n - 1].push_back(v[i][j]);
        }
    }
    int mxtmp = mxn;
    for (int i = 0; i < 2 * n - 1; i++) {
        int tmp = 0;
        for (auto it : ss[i]) {
            tmp += it;
            tmp = max(tmp, 0);
            mxn = max(mxn, tmp);
        }
    }
    cout << mxn;
}