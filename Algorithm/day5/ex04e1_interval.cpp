#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<pair<int, int>> c(N);
    for (int i = 0; i < N; i++) cin >> c[i].second;
    for (int i = 0; i < N; i++) cin >> c[i].first;
    sort(c.begin(), c.end(), less<pair<int,int>>());
    int cnt = 0;
    int endTime = -1;
    for (int i = 0; i < c.size(); i++) {
        if (c[i].second >= endTime) {
            endTime = c[i].first;
            cnt++;
        }
    }
    cout << cnt;
}
