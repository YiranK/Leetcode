class Solution {
public:
    void moveon(vector<vector<int>>& ans, vector<int>& cur, vector<int>& cur_idx, vector<int>& nums, int k, int start) {
        if (k == 0) {
            ans.push_back(cur);
        } else if (k > 0) {
            for (int i = start; i < nums.size(); i++) {
                // do not need this sentence: 'if (find(cur_idx.begin(), cur_idx.end(), i) != cur_idx.end()) continue;',
                // because this is not a problem of permutation.
                // in permutation problems, 'i' start with 0, every 'for' loop needs to check whether current number is in 'cur' or not.
                // for this subset problem, 'i' of next node must start more backward, so do not need to check if it is already in 'cur'.
                cur.push_back(nums[i]);
                //cur_idx.push_back(i);
                
                moveon(ans, cur, cur_idx, nums, k-1, i+1);
                
                cur.pop_back();
                //cur_idx.pop_back();
                
                while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> cur, cur_idx;
        
        if (nums.empty()) return ans;
        
        for (int i = 0; i <= nums.size(); i++) {
            moveon(ans, cur, cur_idx, nums, i, 0);
        }
        
        return ans;
    }
};
