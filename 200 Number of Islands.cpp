class Solution {
public:
    int row, col;
    
    void findAdjacentLand(int x, int y, vector<vector<char>>& grid) {
        if (grid[x][y] != '1') return;
        // mark visited
        grid[x][y] = 'v';
        
        // traverse 4 direction.
        // notice that we do not traverse the nodes whose value is not '1'.
        // don't worry about 'v' nodes. when we traverse a node, we mark its all adjacent '1' nodes as 'v' utterly and thoroughly,
        // which means we already have one whole island.
        // the nodes have already been visited is 'v' now, there's no need to turn back to these 'v' nodes again.
        // thus, we only care about '1' nodes currently.
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i++) {
            if (x+dx[i]<row && x+dx[i]>=0 && y+dy[i]<col 
                && y+dy[i]>=0 && grid[x+dx[i]][y+dy[i]] == '1') findAdjacentLand(x+dx[i], y+dy[i], grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        if (grid.empty()) return 0;
        row = grid.size();
        col = grid[0].size();

        // find from the boundary.
        // notice the '1' on boundary can directly extend horizontally and vertically.
        for (int i = 0; i < row; i++) {
            if (grid[i][0] == '1') {
                findAdjacentLand(i, 0, grid);
                num++;
            }
            // dont't worry. after the 'if' sentence above, if (grid[i][0] == '1').
            // all the adjacent nodes of grid[i][0] have already been to 'v'.
            // any one of them can not enter into 'if (grid[i][col-1] == '1')' sentence below.
            if (grid[i][col-1] == '1') {
                findAdjacentLand(i, col-1, grid);
                num++;
            }
        }

        for (int j = 1; j < col-1; j++) {
            if (grid[0][j] == '1') {
                findAdjacentLand(0, j, grid);
                num++;
            }
            if (grid[row-1][j] == '1') {
                findAdjacentLand(row-1, j, grid);
                num++;
            }
        }
        
        
        // traverse who are not adjacent to boundary land.
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    findAdjacentLand(i, j, grid);
                    num++;
                }
            }
        }
        
        return num;
    }
};

// error-prone points:
// 1. '>=' in (x+dx[i]>=0). the index always can be 0, do not forget the situation of '=' .
// 2. after one call for function 'findAdjacentLand' at one node, we have already marked all adjacent '1' nodes of that node,
//    which means we already have one whole island.
