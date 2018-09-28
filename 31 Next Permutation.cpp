class Solution {
public:
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