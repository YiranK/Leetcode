class Solution {
public:
    void backtracking(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums) {
        // end condition: the number in 'cur' is equal to 'nums'
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
        } else {
            // every 'for' loop is to traverse every possible value of current node
            for (int i = 0; i < nums.size(); i++) {
                // if nums[i] is not in 'cur', function find returns the iterator 'cur.end()'
                if (find(cur.begin(), cur.end(), nums[i]) == cur.end()) {
                    cur.push_back(nums[i]);
                    // every 'backtracking' is a kind of moving on, which means next step.
                    // under the condition of choosing 'nums[i]' to be the value of current node.
                    backtracking(ans, cur, nums);
                    cur.pop_back();
                }
                
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        backtracking(ans, cur, nums);
        return ans;
    }
};
