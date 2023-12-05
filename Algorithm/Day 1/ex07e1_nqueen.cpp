#include <bits/stdc++.h>
using namespace std;

int n, ans = 0, board[12][12] = {0};

bool isSafe(int board[][12], int row, int col) {
    for (int i = 0; i < col; i++) if (board[row][i]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool solve(int board[][12], int col, int n) {
    if (col == n) {
        ans++;
        return true;
    }
    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            res = solve(board, col + 1, n) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

int main() {
    cin >> n;
    solve(board, 0, n);
    cout << ans;
}
