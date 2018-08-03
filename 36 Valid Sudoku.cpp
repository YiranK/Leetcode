class Solution {
public:
    bool helper(vector<vector<char>>& board, int row, int col) {
        set<char> check;
        for (int i = row; i < row+3; i++) {
            for (int j = col; j < col+3; j++) {
                cout << " square who ? " << i << " " << j  << " "<< board[i][j] << endl;
                if (board[i][j] != '.') {
                    if (find(check.begin(), check.end(), board[i][j]) != check.end()) {
                        
                        return false;
                    }
                    check.insert(board[i][j]);
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> check;
        for (int i = 0; i < board.size(); i++) {
            check.clear();
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    if (find(check.begin(), check.end(), board[i][j]) != check.end()) {
                        // cout << " row who ? " << i << " " << j  << " "<< board[i][j] << endl;
                        return false;
                    }
                    check.insert(board[i][j]);
                }
            }
        }
        
        
        for (int j = 0; j < board[0].size(); j++) {
            check.clear();
            for (int i = 0; i < board.size(); i++) {
                set<char>::iterator iter;
                // cout << "  board[i][j]: " << board[i][j] << endl;
                
                if (board[i][j] != '.') {
                   
                    bool x = find(check.begin(), check.end(), board[i][j]) != check.end();
                    // cout << "check: " << x << endl;
                    if (find(check.begin(), check.end(), board[i][j]) != check.end()) {
                        // cout << " col who ? " << i << " " << j  << " "<< board[i][j] << endl;
                        return false;
                    }
                    check.insert(board[i][j]);
                }
            }
        }
        
        for (int k = 0; k <= 2; k++) {
            for (int h = 0; h <= 2; h++) {
                if (!helper(board, k*3, h*3)) return false;
            }
            
        }
        
        return true;
    }
};
