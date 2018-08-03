class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt.find(nums[i]) == cnt.end()) {
                cnt[nums[i]] = i;
            } else {
                int dis = i - cnt[nums[i]];
                if (dis <= k) return true;
                
                // notice: every time you just need to remember the last position of same elements,
                //         for you just want the minimum distance between same elements.
                cnt[nums[i]] = i;
            }
        }
        
        return false;
    }
};
