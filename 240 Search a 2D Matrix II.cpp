class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int row = 0, col = matrix[0].size()-1;
        while (row != matrix.size() && col >= 0) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] < target) {
                row++;
            } else {
                col--;
            }
        }
           
        return false;
    }
};

// error-prone point:
// input: [[]]. even if matrix.size() != 0, it doesn't mean that matrix[0].size() != 0.

// the programming think is that, top corner point is just like the pivot in binary search,
// since it is the largest number in its row, if the target is stil larger than it, the row 0 can be ruled out.
// since it is the smallest number in its column, if the target is still smaller than it, the last column can be ruled out.
// then, in this way, we keep ruleing out row and column, until we find target, or all rows and columns have been ruled out.

// the key point is, to find top corner point as the pivot, for it doesn't increase in row and column simultaneously,
// then every time, we can rule out one of them.
