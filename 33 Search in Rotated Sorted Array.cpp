class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int low = 0, high = nums.size()-1;
        
        while (low < high) {
            int m = (low + high) / 2;
            if (nums[m] == target) return m;
            
            // if [m, high] is absolutely increasing interval
            if (nums[m] < nums[high]) {
                // if "target" is in this increasing interval
                // pay attention to "<=" in "target <= nums[high]"
                if (nums[m] < target && target <= nums[high]) {
                    low = m+1;
                } else {
                    high = m-1;
                }
            // if [low, m] is absolutely increasing interval
            } else {
                if (nums[low] <= target && target < nums[m]) {
                    high = m-1;
                } else {
                    low = m+1;
                }
            }
      
        }
        return nums[low] == target ? low : -1;
    }
};

// points:
// 1. the termination condition of "while" loop is "low == high". so when this loop terminates, "low" must equal to "high".
//    thus, we just need one more comparison in "nums[low]", then can get result.
// 2. notice that we only focus on absolutely increasing interval, and if the target is in this absolutely increasing inteval.
//    thinking in this way is much easier.
// 3. since we have already compared "nums[mid]", we don't need include "=" in "if (nums[m] < target)".
//    but we have not compared "nums[high]" or "nums[low]", do not forget "=" in "if (target <= nums[high])".
// 4. pay attention to the moving steps of "low" and "high". since we have already compare "nums[mid]", we can move to "mid+1" or "mid-1".
