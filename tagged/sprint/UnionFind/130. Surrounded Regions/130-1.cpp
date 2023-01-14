#include <vector>
using namespace std;

struct node {
    int parent;
    int height;
    bool valid;
};

class Solution {
public:
    int find(vector<node>& dsj, int i) {
        if (dsj[i].parent != i) {
            dsj[i].parent = find(dsj, dsj[i].parent);
        }
        return dsj[i].parent;
    }

    void Union(vector<node>& dsj, int i, int j) {
        int set_i = find(dsj, i);
        int set_j = find(dsj, j);
        if (set_i == set_j) return;

        if (dsj[set_i].height >= dsj[set_j].height) {
            dsj[set_j].parent = set_i;
            dsj[set_i].valid = dsj[set_i].valid && dsj[set_j].valid;
            if (dsj[set_i].height == dsj[set_j].height) {
                dsj[set_i].height += 1;
            }
        }
        else {
            dsj[set_i].parent = set_j;
            dsj[set_j].valid = dsj[set_i].valid && dsj[set_j].valid;
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board.front().size();
        vector<node> dsj(n*m);

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (board[i][j] == 'O') {
                    int id = i*m + j;
                    dsj[id].parent = id;
                    dsj[id].height = 1;
                    dsj[id].valid = !(i == 0 || i == n-1 || j == 0 || j == m-1);

                    if (i > 0 && board[i-1][j] == 'O') {
                        Union(dsj, id, (i-1)*m + j);
                    }
                    if (j > 0 && board[i][j-1] == 'O') {
                        Union(dsj, id, i*m + j-1);
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (board[i][j] == 'O') {
                    if (dsj[find(dsj, i*m + j)].valid) {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};