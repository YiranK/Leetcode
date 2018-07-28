// first version
class Solution {
public:
    int row, col;
    
    void findAdjacentLand(int x, int y, vector<vector<char>>& grid, bool& connected) {
        if (grid[x][y] != '1') return;
        if (grid[x][y] == 'v') connected = true;
        grid[x][y] = 'v';
        
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i++) {
            if (x+dx[i]<row && x+dx[i]>=0 && y+dy[i]<col && y+dy[i]>=0) findAdjacentLand(x+dx[i], y+dy[i], grid, connected);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        if (grid.empty()) return 0;
        row = grid.size();
        col = grid[0].size();
        
        
        for (int i = 0; i < row; i++) {
            if (grid[i][0] == '1') {
                bool ifConnected = false;
                findAdjacentLand(i, 0, grid, ifConnected);
                if (!ifConnected) num++;
            }
            if (grid[i][col-1] == '1') {
                bool ifConnected = false;
                findAdjacentLand(i, col-1, grid, ifConnected);
                if (!ifConnected) num++;
            }
        }

        for (int j = 1; j < col-1; j++) {
            if (grid[0][j] == '1') {
                bool ifConnected = false;
                findAdjacentLand(0, j, grid, ifConnected);
                if (!ifConnected) num++;
            }
            if (grid[row-1][j] == '1') {
                bool ifConnected = false;
                findAdjacentLand(row-1, j, grid, ifConnected);
                if (!ifConnected) num++;
            }
        }
        
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    bool ifConnected = false;
                    findAdjacentLand(i, j, grid, ifConnected);
                    if (!ifConnected) num++;
                }
            }
        }
        
        return num;
    }
};
