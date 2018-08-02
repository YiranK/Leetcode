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

// solution 2:
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[1] < nums[0]) return 0;
        if (nums[nums.size()-2] < nums[nums.size()-1]) return nums.size()-1;
        
        int k = nums.size() / 2;
        int low = 0, high = nums.size()-1;
        while (low < high) {
            int mid = (low + high) / 2; // the front middle
            if (nums[mid] < nums[mid+1]) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
};

// this problem is the equivalent to find the local maximum in the vector by using binary search.
// the most delicate solution is that every binary search, compare the middle two numbers to pick the larger one,
// who is more likely to be the local maximum, so then we choose the interval who includes the larger one to binary search again.
 
