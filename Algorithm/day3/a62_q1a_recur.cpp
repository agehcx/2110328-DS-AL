#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

void H(int a, int b, int tp, int bt, int l, int r) {
    if (a-- == 0) v[tp][l] = b;
    else {
        int dx = (l + r) / 2, dy = (tp + bt) / 2;
        H(a, b, tp, dy, l, dx);
        H(a, b - 1, tp, dy, dx, r);
        H(a, b + 1, dy, bt, l, dx);
        H(a, b, dy, bt, dx, r);
    }
}

int main() {
    int a, b; cin >> a >> b;
    v.resize(1 << a);
    for (auto& it : v) it.resize(1 << a);
    H(a, b, 0, 1 << a, 0, 1 << a);
    for (auto& e : v) {
        for (auto it : e) cout << it << ' ';
        cout << '\n';
    }
}