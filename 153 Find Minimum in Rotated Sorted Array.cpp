class Solution {
public:

    int findMin(vector<int>& nums) {
        
        int low = 0, high = nums.size()-1;
        while (low < high) {
            // directly find the ascending interval, and return the first value of this interval to be the minumum.
            if (nums[low] < nums[high]) return nums[low]; 
            
            // if the whole interval is not absolutely ascending, we try to cut it into two parts,
            // to find which one includes falling down.
            int mid = (low + high) / 2;
            if (nums[mid] >= nums[high]) {
                // notice this 'mid+1', for we can find the minimum if we find the absolutely ascending interval.
                // so it's not necessary that we will miss the munimum.
                low = mid + 1;
            } else {
                // notice that we can't minus 1 to 'mid', for maybe 'nums[mid]' is minumum, when it is following the max number.
                // but if we did so, we will turn into the absolutely ascending interval, but the first of it is not the minimum.
                high = mid;
            }
        }
        
        return nums[low];
    }
};

// it's important and not easy to consider the 'while' loop termination condition and the change of interval.
// notice 'low = mid + 1;' in loop, so the termination condition can be 'low < high', for 'low' can move to 'high' position.
// when 'nums[mid] < nums[high]', 'mid' maybe the position of minimum, if we then move to [low, mid-1],
// we will never find the required interval which includes descending, so 'high = mid', 'high' can't move forward anymore.


