#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> v(N);
    vector<int> r(N);
    for (auto& e : v) {
        cin >> e;
        if (e >= 2e9 || e <= -2e9) {
            cout << "NO";return 0;
        }
    }
    iota(r.begin(), r.end(), 1);
    sort(v.begin(), v.end());
    cout << (v == r ? "YES" : "NO");
}