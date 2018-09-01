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


// Right Solution
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        int dy[8] = {2,2,-2,-2,1,1,-1,-1};
        int dx[8] = {1,-1,1,-1,2,-2,2,-2};
        // int dp[N][N] = {0};
        // // cout << sizeof(dp) << endl;
        // // memset(dp, 1, sizeof(dp));
        // for (int i = 0; i < N; i++) {
        //     fill(dp[i], dp[i]+N, 1);
        // }
        vector<vector<double>> dp(N, vector<double>(N,1));
        
        
        for (int k = 1; k <= K; k++) {
            // int t[N][N];
            // // memset(t, 0, sizeof(t));
            // for (int i = 0; i < N; i++) {
            //     fill(t[i], t[i]+N, 0);
            // }
            vector<vector<double>> t(N, vector<double>(N, 0));
            
            // cout << "k: " << k;
            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    for (int i = 0; i < 8; i++) {
                        if (y+dy[i] >= 0 && y+dy[i] < N && x+dx[i] >= 0 && x+dx[i] < N) {
                            t[y][x] += dp[y+dy[i]][x+dx[i]];
                            // cout << " [y+dy[i]][x+dx[i]]: " << y+dy[i] << x+dx[i];
                            // cout << " t[y][x]: " << y << "," << x << ": " << t[y][x] << endl;
                        }                   
                    }
                }
            }
            // cout << k << ": " << dp[0][0] << endl;
            dp = t;
            // for (int i = 0; i < N; i++) {
            //     memcpy(dp[i], t[i], N*sizeof(int));
            // }
            // // memcpy(dp, t, sizeof(t));
        }
        // cout <<dp[r][c];
        return double(dp[r][c]) / pow(8, K);
        
    }
};
