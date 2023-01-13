#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board, int& n, int& m, int i, int j) {
        board[i][j] = '!';
        if (i > 0 && board[i-1][j] == 'O') {
            dfs(board, n, m, i-1, j);
        }
        if (i <= n-2 && board[i+1][j] == 'O') {
            dfs(board, n, m, i+1, j);
        }
        if (j > 0 && board[i][j-1] =='O') {
            dfs(board, n, m, i, j-1);
        }
        if (j <= m-2 && board[i][j+1] == 'O') {
            dfs(board, n, m, i, j+1);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board.front().size();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if (board[i][j] == 'O') {
                        dfs(board, n, m, i, j);
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (board[i][j] == '!') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};