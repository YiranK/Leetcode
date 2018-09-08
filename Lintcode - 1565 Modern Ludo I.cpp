1565. Modern Ludo I

//Description
//There is a one-dimensional board with a starting point on the far left side of the board and an end point on the far right side of the board. There are several positions on the board that are connected to other positions, ie if A is connected to B, then when chess falls at position A, you can choose whether to move the chess from A to B. And the connection is one way, which means that the chess cannot move from B to A. Now you have a six-sided dice, find the minimum steps to reach the end.

//the index starts from 1.
//length > 1
//The starting point is not connected to any other location
//connections[i][0] < connections[i][1]

class Solution {
public:
    /**
     * @param length: the length of board
     * @param connections: the connections of the positions
     * @return: the minimum steps to reach the end
     */
     
    // static bool cmp(vector<int> a, vector<int> b) {
    //     return a[0] < b[0];
    // }
    
    
    int modernLudo(int length, vector<vector<int>> &connections) {
        // sort(connections.begin(), connections.end(), cmp);
        // vector<vector<int>> nodupli;
        // for (int i = 0; i < connections.size(); i++) {
        //     // cout << connections[i][0] << " " << connections[i][1];
        //     if (!nodupli.empty() && connections[i][0] <= nodupli.back()[1]) {
        //         int low = min(connections[i][0], nodupli.back()[0]);
        //         int high = max(connections[i][1], nodupli.back()[1]);
        //         nodupli.back() = {low,high};
        //     } else {
        //         nodupli.push_back(connections[i]);
        //     }
        // }
        
        // int step;
        
        // if (!nodupli.empty()) {
        //     for (int i = 0; i < nodupli.size(); i++) {
        //         cout << nodupli[i][0] << " " << nodupli[i][1] << endl;
        //     }
            
        //     step = ceil(double(nodupli[0][0] - 1)/6);
        //     // cout << step; 
        //     for (int i = 1; i < nodupli.size(); i++) {
        //         step += ceil(double(nodupli[i][0] - nodupli[i-1][1])/6);
        //         // cout << step;
        //     }
        //     step += ceil(double(length - nodupli.back()[1])/6);
        // } else {
        //     step = ceil(double(length - 1)/6);
        // }
        
        
        // return step;
        
        vector<int> dp(length+1, INT_MAX/2), conn(length+1);
        for (int i = 0; i < connections.size(); i++) {
            conn[connections[i][0]] = connections[i][1];
        }
        
        for (int i = 1; i < length+1; i++) {
            if (i <= 1+6) {
                dp[i] = 1;
            } else {
                for (int j = i-6; j < i; j++) {
                    dp[i] = min(dp[j]+1, dp[i]);
                }
            }
            
            dp[conn[i]] = min(dp[conn[i]], dp[i]);
        }
        
        return dp[length];
    }
};
