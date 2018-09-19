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

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {      
        if (nums.empty()) return 0;
        // the lower pointer `i`, to denote the last not duplicated element
        int i = 0;
        // the faster pointer `j`, to traverse whole array
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};