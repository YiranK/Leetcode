// first version: complex
// use vector<vector<bool> to indicate visited (i,j).
// use vector<pair<int,int>> to indicate (i,j) of 'O' needed change to 'X'.
// use queue<pair<int,int>> to indicate (i,j) of next visiting.
// actually, there is no need to construct so many containers,
// for every value in char 'board' can change itself as a mark to indicate whether a node is visited or not, and is going to change to 'X' or not.

// Also it's not necessary to record the queue size each time, for there is no requirements for indicate each level of traverse.

// error-pront points:
// 1. need to update visited[i][j]. if the boundary 'O's aren't marked as 'false', it will loop again and again,
//    which will result in memory limit exceed.
// 2. pay attention to that if some value is found in a vector, 'find' function return an iterator which != .end().
// 3. erase some value at position 'pos' in a vector, 'tochange.erase(tochange.begin()+pos);', not erase a interval.
 
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int height = board.size();
        if (!height) return;
        int width = board[0].size();
        
        vector<vector<bool>> visited(height, vector<bool>(width, false));  
        vector<pair<int,int>> tochange;
        queue<pair<int,int>> tovisit;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == 'O') {     
                    if (i == 0 || (i == height-1) || j == 0 || (j == width-1)) {
                        visited[i][j] = true;
                        tovisit.push(make_pair(i, j));
                    } else {
                        tochange.push_back(make_pair(i,j));
                    }
                }
            }
        }
        
        // cout << "\nafter boudary: \n";
        // for (int i = 0; i < height; i++) {
        //     for (int j = 0; j < width; j++) {
        //         cout << visited[i][j] <<" ";
        //     }
        //     cout <<endl;
        // }
        // cout << "visited right" <<endl;
        
        
        queue<pair<int,int>> test(tovisit);
        int ts = test.size();
//         for (int i = 0; i < ts; i++) {
//             cout << "(" << test.front().first << ", " << test.front().second << "), ";
//             test.pop();
//         }
//         cout <<endl << "tochange : \n" ;
        
        
//         for (int i = 0; i < tochange.size(); i++) {
//             cout << "(" << tochange[i].first << ", " << tochange[i].second << "), ";
//         }
// //         cout << "tochange right" << endl;
        
        
        //if (tochange.size()+tovisit.size() == height*width) return;
        
        while (!tovisit.empty()) {
            
            int num = tovisit.size();
            while (num--) {
                int i = tovisit.front().first;
                int j = tovisit.front().second;
                tovisit.pop();
                //cout << endl << num << " i:" << i << " j:" << j;
                
                if (i>1 && !visited[i-1][j] && board[i-1][j] == 'O') {
                    tovisit.push(make_pair(i-1, j));
                    visited[i-1][j] = true;
                    if (find(tochange.begin(), tochange.end(), make_pair(i-1, j)) != tochange.end()) {
                        int pos = distance(tochange.begin(),find(tochange.begin(), tochange.end(), make_pair(i-1, j)));
                        tochange.erase(tochange.begin()+pos);
                        //cout << " remove:" << i-1 << j << " ";
                    }   
                }
                if (i+1<height && !visited[i+1][j] && board[i+1][j] == 'O') {
                    tovisit.push(make_pair(i+1, j));
                    visited[i+1][j] = true;
                    if (find(tochange.begin(), tochange.end(), make_pair(i+1, j)) != tochange.end()) {
                        int pos = distance(tochange.begin(),find(tochange.begin(), tochange.end(), make_pair(i+1, j)));
                        tochange.erase(tochange.begin()+pos);
                        //cout << " remove:" << i+1 << j << " ";
                    }
                    
                }
                if (j>1 && !visited[i][j-1] && board[i][j-1] == 'O') {
                    tovisit.push(make_pair(i, j-1));
                    visited[i][j-1] = true;
                    if (find(tochange.begin(), tochange.end(), make_pair(i, j-1)) != tochange.end()) {
                        int pos = distance(tochange.begin(),find(tochange.begin(), tochange.end(), make_pair(i, j-1)));
                        tochange.erase(tochange.begin()+pos);
                        //cout << " remove:" << i << j-1 << " ";
                    }
                }
                if (j+1<width && !visited[i][j+1] && board[i][j+1] == 'O') {
                    tovisit.push(make_pair(i, j+1));
                    visited[i][j+1] = true;
                    if (find(tochange.begin(), tochange.end(), make_pair(i, j+1)) != tochange.end()) {
                        int pos = distance(tochange.begin(),find(tochange.begin(), tochange.end(), make_pair(i, j+1)));
                        tochange.erase(tochange.begin()+pos);
                        //cout << " remove:" << i << j+1 << " ";
                    }
                }
            }
            
            // // print visited
            // cout << endl;
            // for (int i = 0; i < height; i++) {
            //     for (int j = 0; j < width; j++) {
            //         cout << visited[i][j] <<" ";
            //     }
            //     cout <<endl;
            // }
            // cout << "visited right" <<endl;
            
        }
        
        for (int idx = 0; idx < tochange.size(); idx++) {
            int i = tochange[idx].first;
            int j = tochange[idx].second;
            board[i][j] = 'X';
        }
        
        // print finally tochange
        // cout << "finally" << endl;
        // for (int i = 0; i < tochange.size(); i++) {
        //     cout << "(" << tochange[i].first << ", " << tochange[i].second << "), ";
        // }
            
    }
};


// second version:
// every value in char 'board' can change itself as a mark to indicate whether a node is visited or not, and is going to change to 'X' or not.
// '1' indicates visited and not change.
// when the queue is empty, the traverse is complete.
// at this time, left 'O' is goint to change to 'X', and '1' back to 'O'.
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int height = board.size();
        if (!height) return;
        int width = board[0].size();
        
        queue<pair<int,int>> tovisit;
        
        for (int i = 0; i < height; i++) {
            if (board[i][0] == 'O') {
                tovisit.push(make_pair(i, 0));
                board[i][0] = '1';
            }
            if (board[i][width-1] == 'O') {
                tovisit.push(make_pair(i, width-1));
                board[i][width-1] = '1';
            }
        }
        for (int j = 0; j < width; j++) {
            if (board[0][j] == 'O') {
                tovisit.push(make_pair(0, j));
                board[0][j] = '1';
            }
            if (board[height-1][j] == 'O') {
                tovisit.push(make_pair(height-1, j));
                board[height-1][j] = '1';
            }
        }
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                 cout << board[i][j] << " ";
            }
            cout << "\n";
        }
   
        while (!tovisit.empty()) {
            int i = tovisit.front().first;
            int j = tovisit.front().second;
            tovisit.pop();

            if (i>1 && board[i-1][j] == 'O') {
                tovisit.push(make_pair(i-1, j));
                board[i-1][j] = '1';
            }
            if (i+1<height && board[i+1][j] == 'O') {
                tovisit.push(make_pair(i+1, j));
                board[i+1][j] = '1';
            }
            if (j>1 && board[i][j-1] == 'O') {
                tovisit.push(make_pair(i, j-1));
                board[i][j-1] = '1';
            }
            if (j+1<width && board[i][j+1] == 'O') {
                tovisit.push(make_pair(i, j+1));
                board[i][j+1] = '1';
            }
            
        }
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                 if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
         for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                 if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
            
    }
};



// since each node has 4 direction to go, it can be considered as a combination of dfs and bfs.
// third version: DFS
class Solution {
public:
    int row, col;
                       
    void check(int x, int y, vector<vector<char>>& board) {
        if (board[x][y] != 'O') return;
        board[x][y] = '1';
        
        //debug
        // cout << "recusion of (" << x << ", " << y << ") "<< endl;
        
        // continue check by recursion.
        // for each node, it will visit its adjacents in 4 direction.
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i++) {
            if (x+dx[i]<row && x+dx[i]>0 && y+dy[i]<col && y+dy[i]>0) {
                check(x+dx[i], y+dy[i], board);
                
                
                // debug
                // cout << "(" << x+dx[i]  << ", " << y+dy[i] << ") " << endl;
                // cout << "board:\n";
                // for (int i = 0; i < row; i++) {
                //     for (int j = 0; j < col; j++) {
                //         cout << board[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << "board finish\n\n";
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        // special case: empty board
        if (board.empty()) return;
        row = board.size();
        col = board[0].size();
        
        
        // find the boundary 'O'.
        // for each boundary 'O', recursively visit its adjacent nodes to check by DFS.
        for (int i = 0; i < row; i++) {
            check(i, 0, board);
            check(i, col-1, board);
        }
        for (int j = 0; j < col; j++) {
            check(0, j, board);
            check(row-1, j, board);
        }
        
        // finally, remained 'O' need to change to 'X', while '1' change back to 'O'.
        // we never change the original 'X', so it's no need to care about original 'X'.
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
};

// error-prone point:
// in 'check' function, traversing 'dx' and 'dy' use 'i' and 'j',
// so the coordinate variable passed in this function should not be 'i' and 'j', or it will result in error.

// Question:
// if using BFS, can we do not exploit the container queue, instead use recursion?


