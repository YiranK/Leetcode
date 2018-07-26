class Solution {
public:
    void moveon(vector<vector<int>>& ans, vector<int>& cur, int n, int left, int start) {
        if (left <= 0) {
            ans.push_back(cur);
        } else {
            // to avoid duplicates, 'i' needs to be initialized to the value of 'start'.
            // for the value of current node must be larger than the value of last node (also the index of node),
            // which means it must be more backward in 1...n
            for (int i = start; i <= n; i++) {
                if (find(cur.begin(), cur.end(), i) == cur.end()) {
                    cur.push_back(i);
                    // pay attention to 'left-1', 'i+1'.
                    // 'left-1': the 'for' loop need to traverse all possible value of current node,
                    //           so left' itself can't be changed, which means 'left--' is wrong.
                    // 'i+1': when move on to next node, the value can be choosed must be more bakward,
                    //        which means the value of next node must be larger than 'i'.
                    //        notice that 'i' is the variable that increase during 'for' loop, do not use 'start'.
                    moveon(ans, cur, n, left-1, i+1);
                    cur.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        moveon(ans, cur, n, k, 1);
        return ans;
    }
};
