class Solution {
public:
    void moveon(vector<vector<int>>& ans, vector<int>& cur, int numk_left, int remain_tar, int start) {
        // notice the number 'k' is also a constriction, do not forget it.
        if (remain_tar == 0 && numk_left == 0) {
            ans.push_back(cur);
        } else if (remain_tar && numk_left){
            // 'i' is initialized with 'start', because not every integer in '1...n' need to be used.
            // in order to avoid duplicates, restrict the numbers in 'cur' to be incresing£¬
            // which means, when move on to next node, the value needs to be choosed more backward in '1...n'.
            for (int i = start; i <= 9; i++) {
                cur.push_back(i);
                moveon(ans, cur, numk_left-1, remain_tar-i, i+1);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        moveon(ans, cur, k, n, 1);
        return ans;
    }
};
