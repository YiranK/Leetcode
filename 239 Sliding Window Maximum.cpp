class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int dp[nums.size()] = {0};
        if (nums.empty()) return vector<int>();
        vector<int> res;
        int size = k % 2 == 1 ? nums.size()-k/2 : nums.size()-k/2+1;
        for (int i = k/2; i < size; i++) {
            int max_win = nums[i];
            for (int j = 1; j <= k/2; j++) {
                // odd number
                if (k % 2 || j <= k/2-1) {
                    max_win = max(max(max_win, nums[i-j]), nums[i+j]);
                } else {
                    // cout << i << " " << j << endl;
                    // if (i+j >= nums.size()) break;
                    max_win = max(max_win, nums[i-j]);
                }
                
            }
            res.push_back(max_win);
        }
        return res;
    }
};