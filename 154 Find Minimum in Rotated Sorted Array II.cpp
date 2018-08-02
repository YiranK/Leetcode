class Solution {
public:
    int findMin(vector<int>& nums) {
        set<int> rd(nums.begin(), nums.end());
        nums.assign(rd.begin(), rd.end());
        int low = 0, high = nums.size()-1;
        while (low < high) {
            if (nums[low] < nums[high]) return nums[low];
            int mid = (low + high) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return nums[low];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        // set<int> rd(nums.begin(), nums.end());
        // nums.assign(rd.begin(), rd.end());
        int low = 0, high = nums.size()-1;
        while (low < high) {
            if (nums[low] < nums[high]) return nums[low];
            int mid = (low + high) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                high = mid;
            } else {
                // a surprising silution!
                high--;
            }
        }
        
        return nums[low];
    }
};

// <Find Minimum in Rotated Sorted Array II> is different from <Find Minimum in Rotated Sorted Array> for it includes duplicates.
// especially when (nums[mid] == nums[high]), it will trap into some troubles.
// because 'nums[high]' matters to the route across 'while' loop, to avoid the duplicate number by simply moving 'high' forward is OK.
