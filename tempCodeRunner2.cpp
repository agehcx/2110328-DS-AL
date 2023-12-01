#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N = 9;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                for (int k = 0; k < N; k++) {
                    cnt++;
                    // cout << i << ' ' << j << ' ' << k << '\n';
                }
            } else {
                cnt++;
            }
        }
    }
    cout << cnt;
}