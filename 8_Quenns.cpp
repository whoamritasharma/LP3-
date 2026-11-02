#include <iostream>
#include <vector>
using namespace std;

// Check if a queen can safely be placed at board[row][col]
bool isSafe(int row, int col, vector<string>& board, int n) {
    int duprow = row, dupcol = col;
    while (row >= 0 && col >= 0) { if (board[row][col] == 'Q') return false; row--; col--; } // Upper-left diagonal
    row = duprow; col = dupcol;
    while (col >= 0) { if (board[row][col] == 'Q') return false; col--; } // Left row
    row = duprow; col = dupcol;
    while (row < n && col >= 0) { if (board[row][col] == 'Q') return false; row++; col--; } // Lower-left diagonal
    return true;
}

void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    if (col == n) { ans.push_back(board); return; } // Base case: all queens placed successfully
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';          // Place queen
            solve(col + 1, board, ans, n);  // Recurse for the next column
            board[row][col] = '.';          // Backtrack and remove queen
        }
    }
}

int main() {
    int n = 8;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    board[0][0] = 'Q'; // First queen pre-placed as per problem statement
    solve(1, board, ans, n);
    if (!ans.empty()) {
        cout << "First Valid 8-Queen Matrix Configuration:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << ans[0][i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}