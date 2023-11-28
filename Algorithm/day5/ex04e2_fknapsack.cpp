#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double w; int n;
    cin >> w >> n;
    vector<pair<double, pair<double, double>>> vec(n);

    for (int i = 0; i < n; i++) cin >> vec[i].second.first;
    for (int i = 0; i < n; i++) cin >> vec[i].second.second, vec[i].first = vec[i].second.first / vec[i].second.second;
    sort(vec.begin(), vec.end(), greater<pair<double, pair<double, double>>>());
    long double cnt = 0;
    for (auto& it : vec) {
        if (w < 0) continue;
        if (it.second.second <= w) cnt += it.second.first;
        else  cnt += it.first * w;
        w -= it.second.second;
    }
    cout << fixed << setprecision(4) << cnt << endl;
}

