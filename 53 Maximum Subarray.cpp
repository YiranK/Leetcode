class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            
            // if previous sum is negative, reset ths sum to be 0, and start add sum from current number(nums[i]).
            // no matter what latter sum is, the latter sum add this previous negative sum will get a smaller sum.
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            if (sum > max) max = sum;
        }
        
        return max;
    }
};

// Kadane's algorithm
