class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool helper(vector<vector<char>> board, int m, int n, int row, int col, string word, int idx) {
        if (row >= m || row < 0 || col >= n || col < 0 || board[row][col] != word[idx]) return false;
        if (idx == word.length()-1) {
            return true;
        } else {
            board[row][col] = '#';
            bool hasPath = false;
            // do not use for loop, it will wait for all the results to return, therefore results in time limited exceed.
            // for (int i = 0; i < 4; i++) {
            //     int drow = row + dirs[i][0];
            //     int dcol = col + dirs[i][1];
            //     if (drow < m && drow >= 0 && dcol < n && dcol >= 0 && board[drow][dcol] == word[idx]) {
            //         hasPath |= helper(board, m, n, drow, dcol, word, idx+1);
            //     }
            // }
            hasPath |= helper(board, m, n, row+1, col, word, idx+1) || helper(board, m, n, row, col+1, word, idx+1)
                || helper(board, m, n, row-1, col, word, idx+1) || helper(board, m, n, row, col-1, word, idx+1);
            return hasPath;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int m = board.size(), n = board[0].size();
        bool hasPath = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // cout << i << j << endl;
                if (helper(board, m, n, i, j, word, 0)) {
                    return true; 
                }
            }
        }
        
        return false;
    }
};
// do not use for loop, it will wait for all the results to return, therefore results in time limited exceed.