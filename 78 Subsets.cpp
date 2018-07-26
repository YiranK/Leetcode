class Solution {
public:
    void moveon(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums, int k, int start) {
        if (k == 0) {
            ans.push_back(cur);
        } else if (k > 0) {
            for (int i = start; i < nums.size(); i++) {
                if (find(cur.begin(), cur.end(), nums[i]) != cur.end()) continue;
                cur.push_back(nums[i]);
                // error-prone point: (k-1), k needs decreasing during the step moving on.
                moveon(ans, cur, nums, k-1, i+1);
                cur.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        
        for (int i = 0; i <= nums.size(); i++) {
            moveon(ans, cur, nums, i, 0);
        }
        return ans;
    }
};
