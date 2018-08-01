class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ans;
        vector<int> res;

        if (nums1.empty() || nums2.empty()) return res;
        if (nums1.size() < nums2.size()) return intersect(nums2, nums1);
        
        for (int key : nums1) {
            if (ans.find(key) == ans.end())
                ans[key] = 1;
            else
                ans[key]++;
            // cout << key << " " << ans[key] << endl;
        }
        
        for (int key : nums2) {
            if (ans.find(key) != ans.end() && ans[key] > 0) {
                res.push_back(key);
                ans[key]--;
            }
        }
        
       
        return res;
    }
};

// error-prone points:
// 1. when vector<int> a, a is empty, a.begin() will result in runtime error: reference binding to null pointer of type 'value_type'.
