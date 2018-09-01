// Time limited exceed
class Solution {
public:
    int dy[8] = {2,2,-2,-2,1,1,-1,-1};
    int dx[8] = {1,-1,1,-1,2,-2,2,-2};
    int connected[25][25][25][25] = {0};
    
    
    void DFS(int& count, int N, int k, int r, int c) {
        if (k == 0) {
            count++;
            return;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (connected[r][c][i][j] == 1) {
                    DFS(count, N, k-1, i, j);
                }
            }
        }
        
    }
    
    double knightProbability(int N, int K, int r, int c) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                for (int i = 0; i < 8; i++) {
                    if (y+dy[i] >= 0 && y+dy[i] < N && x+dx[i] >= 0 && x+dx[i] < N) {
                        connected[y][x][y+dy[i]][x+dx[i]] = 1;
                    }                   
                }
            }
        }
        
        int count = 0;
        DFS(count, N, K, r, c);
        cout << double(count);
        return double(count)/pow(8, K);     
    }
};



