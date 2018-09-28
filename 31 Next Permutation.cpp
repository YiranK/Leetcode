class Solution {
public:
    // no need for this function, because you just scan from right to left,
    // use while loop to stop, when you meet the requirement of nums[i] < nums[i+1]
    // (notice that there is no "=", because you need to find the strict larger one permutation)
    bool strictDesc(vector<int>& nums, int low) {
        for (int i = low; i < nums.size()-1; i++) {
            if (nums[i] < nums[i+1]) return false;
        }
        return true;
    }
    
    void nextPermutation(vector<int>& nums) {
        int i;
        for (i = nums.size()-2; i >= 0; i--) {
            if (!strictDesc(nums, i)) {
                sort(nums.begin()+i+1, nums.end());
                // cout << i+1;
                // for (int k = 0; k < nums.size(); k++) {
                //     cout << nums[k] << endl;
                // }
                // if not strict descent, find the nearest num greater than current nums[i]
                for (int j = i+1; j < nums.size(); j++) {
                    if (nums[j] > nums[i]) {
                        int tmp = nums[j];
                        nums[j] = nums[i];
                        nums[i] = tmp;
                        break;
                    }
                }
                break;
            }   
            
        }
        
        // cout << i << strictDesc(nums, 0);
        if (i == -1) {
            sort(nums.begin(), nums.end());
        }
        
    }
};


class Solution {
public:
    void swap(vector<int>& nums, int low, int high) {
        int tmp = nums[low];
        nums[low] = nums[high];
        nums[high] = tmp;
    }
    
    void reverse(vector<int>& nums, int low) {
        int high = nums.size()-1;
        while (low < high) {
            swap(nums, low++, high--);
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while (i >= 0 && nums[i] >= nums[i+1]) i--;
        // if the whole vector is passed, after the while loop, `i` becomes -1.
        // This situation means the vector is in desc order.

        if (i < 0) {
            reverse(nums, 0);
        } else {
            // notice that the right section is in desc order, so no need to sort them, just simply reverse them to ascen order
            reverse(nums, i+1);
            int j = i+1;
            // look up for the first element larger than nums[i], in ascen order
            while (j < nums.size() && nums[j] <= nums[i]) j++;
            swap(nums, i, j);
        }
    }
};