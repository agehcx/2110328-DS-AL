#include <iostream>
int dp[101][101];
int main() {
    int N; std::cin >> N;
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= N; j++)
            dp[i][j] = (j >= i ? dp[i - 1][j] + dp[i][j - i] : dp[i - 1][j]);
    std::cout << dp[N][N];
}
