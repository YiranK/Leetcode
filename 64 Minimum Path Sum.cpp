// space compexity O(n^2) solution:
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (row==0 && col>0) grid[row][col] += grid[row][col-1];
                if (col==0 && row>0) grid[row][col] += grid[row-1][col];
                if (row>0 && col>0) grid[row][col] += min(grid[row-1][col], grid[row][col-1]);
            }
        }
        return grid.back().back();       
    }
};


// remember: every node can just come from left or top, so choose a smaller sum between its left node and top node.
//           it's a proceess accumulation.



// linear space solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int row = grid.size();
        int col = grid[0].size();
        vector<int> accuMinonROW(grid[0]);
        // initialize row 0.
        for (int i = 1; i < col; i++) accuMinonROW[i] = accuMinonROW[i] + accuMinonROW[i-1];
        
        for (int r = 1; r < row; r++) {
            // special operation of 0th node on each row. 
            // for it's just related to accmulation with 0th node on last row, and not relevant to calculate minimum.
            accuMinonROW[0] += grid[r][0];
            
            for (int c = 1; c < col; c++) {
                // notice that 'accuMinonROW[c-1]' is updated befoe this sentence, 
                // which means it is min value of (c-1)th node on current row.
                // while 'accuMinonROW[c]' has not been updated yet, which stands for cth node on last row.
                // after this sentence, it is updated to current row.
                accuMinonROW[c] = min(accuMinonROW[c], accuMinonROW[c-1]) + grid[r][c];
            }            
        }
        return accuMinonROW[col-1];  
    }
};     
