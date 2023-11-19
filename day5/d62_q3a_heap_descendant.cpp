#include <bits/stdc++.h>
using namespace std;

set<int> s;
int N, K;

void rec(int x) {
    s.insert(x);
    if (2 * x + 1 < N) rec(2 * x + 1);
    if (2 * x + 2 < N) rec(2 * x + 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    rec(K);
    cout << s.size() << '\n';
    for (auto it : s) cout << it << ' ';
}