#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int f, w, n; cin >> f >> w >> n;
    vector<bool> light(n + 1, false);
    for (int i = 0; i < f; i++) {
        int x; cin >> x;
        light[x] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (light[i]) {
            cnt++;
            for (int j = i; j <= i + w + w; j++) {
                light[j] = false;
            }
            i += w + w;
        }
    }
    cout << cnt;

}
