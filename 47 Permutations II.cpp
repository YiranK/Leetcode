class Solution {
public:
    void moveon(vector<vector<int>>& ans, vector<int>& cur, vector<int>& cur_idx, vector<int>& nums) {
        // end condition: number in 'cur' is equal to number in 'nums'.
        // plus, 'cur' is not in 'ans', for the repeated numbers may result in duplicates contained.
        if (cur.size() == nums.size() && find(ans.begin(), ans.end(), cur) == ans.end()) {
            ans.push_back(cur);
        } else {
            
            for (int i = 0; i < nums.size(); i++) {
                // to satisfy the requirements of unique, the used index must be recorded in 'cur_idx'.
                if (find(cur_idx.begin(), cur_idx.end(), i) == cur_idx.end()) {
                    // remeber the index of used numbers.
                    cur_idx.push_back(i);
                    cur.push_back(nums[i]);
                    // move on to next step, under the condition of choosing 'nums[i]' to be the value of current node.
                    moveon(ans, cur, cur_idx, nums);
                    
                    // backtrack, remeber 'cur_idx' also needs backtracking.
                    cur.pop_back();
                    cur_idx.pop_back();
                }
            }
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        vector<int> cur_idx;
        
        if (nums.empty()) return ans;
        moveon(ans, cur, cur_idx, nums);
        return ans;
    }
};
