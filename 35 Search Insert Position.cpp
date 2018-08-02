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


// better strategy:
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while (low <= high) {
        	// the front midlle
            int mid = (low + high) / 2;
            if (target == nums[mid]) return mid;
            if (target < nums[mid]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};
// [better strategy for 1.] change loop condition from 'low < high' to 'low <= high'.
// since when 'low == high', 'mid' equals to 'low', and in the loop it is automatic to compare 'target' and 'nums[mid]'.
// if (target < nums[mid]), the insert position is 'low' unchangedly, and nums[mid] is pushed backwards.
// if (target > nums[mid]), the 'target' should be put backwards, and 'low' becomes backwards simultaneously by 'low = mid+1;'.
//                          so the 'low' indicates the position to insert perfectly.
