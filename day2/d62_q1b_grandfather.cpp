#include <iostream>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::unordered_map<std::string, std::string> mp;
    std::string a, b;
    for(;n--;)std::cin >> a >> b, mp[b] = a;
    for(;m--;){
        std::cin >> a >> b;
        std::cout << (mp[mp[a]] == mp[mp[b]] && mp[mp[a]] != "" && mp[mp[b]] != "" && a != b ? "YES\n" : "NO\n");
    }
}