class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[1] < nums[0]) return 0;
        if (nums[nums.size()-2] < nums[nums.size()-1]) return nums.size()-1;
        
        int k = nums.size() / 2;
        int low = 0, high = nums.size()-1;
        while (low < high) {
            int k = (high + low + 1) / 2;
            if (nums[k] > nums[k-1] && nums[k] > nums[k+1]) {
                return k;
            } else {
                if (nums[k-1] > nums[k]) {
                    high = k;
                } else {
                    low = k;
                }
            }
        }
        
        return 0;
    }
};


