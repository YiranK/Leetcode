class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==0 || n==0) return 0;
        if (m==1 || n==1) return 1;
        
        vector<vector<int>> pathnum(n, vector<int>(m, -1));
        pathnum[0] = {1}; // n=1, (row).
        for (int row = 0; row < n; row++) pathnum[row][0] = 1; // every first node in each row fills with '1'.
        
        // extend column from (row=n, column=1), which means coordinate (n-1,0), to (n-1,1), (n-1,2)... (n-1, m-1).
        // so traverse 'col' from 1 to (n-1).
        for (int col = 1; col < m; col++) {
            int cur_num = 0;
            for (int row = 0; row < n; row++) {
                
                // [false handle]
                // if you skip 'pathnum[row][col]', you will also ignore the accumulation 'cur_num += pathnum[row][col-1] * 1;'
                // you may think since 'pathnum[row][col]' is stored, the accumulation will not be effected.
                // but the accumulation is by column, while you traverse the nodes by row.
                // for example, if you skip (1,2), you lose the accumulation with (1,1),
                // next, you traverse (2,2), you accumulate (2,1), but as you lose accumulation with (1,1),
                // you get wrong value in (2,2).
                
                // if (pathnum[row][col]!=-1) {
                //     cout << "row, col: " << row << "," << col << "   value:" << pathnum[row][col] << endl;
                //     continue;
                // }
                
                
                cur_num += pathnum[row][col-1] * 1;
                cout << "row, col: " << row << "," << col << "   cur_num:" << cur_num << endl;
                pathnum[row][col] = cur_num;
                // if (row < m && col < n) pathnum[col][row] = cur_num;
            }
        }
     
        return pathnum[n-1][m-1];
        
    }
};

// I store the whole map of path number, but for this case, the whole map is not absolutely needed.
// from my process, we can also see it's a kind of accumulation.
// but in my original idea, I just thought extend (n-1) row from left to right.
// and then find that in this process, not only values in (n-1) row are needed, the previous rows are also needed.
// so I store the previous rows, and at the same time accmulate from top to bottom.

// I also thought that 'col' and 'row' can exchange. if we get 'pathnum[row][col]', we can also get 'pathnum[col][row]'.
// but in that way, we will lose the accumulation with 'pathnum[row][col-1]',
// while we only have the value of 'pathnum[row][col]' now, and it is no use to accumulation row by row in previous column.
// see details in code comment in [false handle].


// error-prone points:
// 1. if (pathnum[row][col]) , if (pathnum[row][col]>0) is different.
//    when pathnum[row][col] == -1, if (pathnum[row][col]) also true.
