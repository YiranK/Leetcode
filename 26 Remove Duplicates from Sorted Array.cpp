class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size()-1;
        for (int i = 1; i <= k; i++) {
            if (nums[i] != nums[i-1]) continue;
            int tmp = nums[i];
            for (int j = i; j < k; j++) {
                nums[j] = nums[j+1];
            }
            nums[k] = tmp;
            k--;
            i--;
        }
        // for (int i = 0; i < nums.size(); i++){
        //     cout << nums[i] << " ";
        // }
        return k+1;
    }
};