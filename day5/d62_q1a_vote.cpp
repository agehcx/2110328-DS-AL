#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int> pq;
    map<string, int> mp;
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        mp[x]++;
    }
    for (auto &it : mp) pq.push(it.second);
    int prev = 0;
    while (k-- && !pq.empty()) {
        prev = pq.top();
        pq.pop();
    }
    std::cout << prev;
}