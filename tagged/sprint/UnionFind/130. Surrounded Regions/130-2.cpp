#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int& n, int& m, int i, int j) {
        board[i][j] = '!';
        bool res = !(i == 0 || i == n-1 || j == 0 || j == m-1);
        if (i > 0 && board[i-1][j] == 'O') {
            res = dfs(board, n, m, i-1, j) && res;
        }
        if (i <= n-2 && board[i+1][j] == 'O') {
            res = dfs(board, n, m, i+1, j) && res;
        }
        if (j > 0 && board[i][j-1] =='O') {
            res = dfs(board, n, m, i, j-1) && res;
        }
        if (j <= m-2 && board[i][j+1] == 'O') {
            res = dfs(board, n, m, i, j+1) && res;
        }
        return res;
    }
    
    void flip(vector<vector<char>>& board, int& n, int& m, int i, int j) {
        board[i][j] = 'X';
        if (i > 0 && board[i-1][j] == '!') {
            flip(board, n, m, i-1, j);
        }
        if (i <= n-2 && board[i+1][j] == '!') {
            flip(board, n, m, i+1, j);
        }
        if (j > 0 && board[i][j-1] =='!') {
            flip(board, n, m, i, j-1);
        }
        if (j <= m-2 && board[i][j+1] == '!') {
            flip(board, n, m, i, j+1);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board.front().size();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (board[i][j] == 'O' && dfs(board, n, m, i, j)) {
                    flip(board, n, m, i, j);
                }
            }
        }
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (board[i][j] == '!') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};