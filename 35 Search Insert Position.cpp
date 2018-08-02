class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while (low < high) {
        	// the front midlle
            int mid = (low + high) / 2;
            if (target == nums[mid]) return mid;
            if (target < nums[mid]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        if (nums[low] < target) {
            return low+1;
        } else {
            return low;
        }
        
    }
};

// 1. pay attention to the insert position.
//    since when 'while' loop terminates, low == high, so comparing nums[low] or nums[high] to target are both ok.
// 2. int mid = (low + high) / 2; the middle is set to be front middle.
// 3. when reset the interval boundary, like 'high = mid-1;' and 'low = mid+1;' we do not recalculate 'nums[mid]' again.
