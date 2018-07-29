class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        vector<int> maxAtCurNode(nums);
        maxAtCurNode[0] = nums[0];
        maxAtCurNode[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); i++) {
            maxAtCurNode[i] = max(maxAtCurNode[i-2]+nums[i], maxAtCurNode[i-1]);
        }
        return maxAtCurNode.back();
    }
};

// error-prone points;
// 1. consider if 'nums.empty()'.
// 2. pay attenation to 'maxAtCurNode[1]', 'max(nums[0], nums[1])' instead of 'nums[1]'.


// max or min problem:
// traverse each node, calculate the best choice till current node.
// like, situation (1): steal [i-2] house, and i can steal [i] house too.
//       situation (2): steal [i-1] house, and i can not steal this current [i] house.
//       pick the maximum value between situation(1) and (2) to be the best choice on current node.
//       thus, I will never come back to consider the nodes before current node.


// O(1) space complexity solution:
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int pp = nums[0], p = max(nums[0], nums[1]), cur;
        if (nums.size() == 1) return pp;
        if (nums.size() == 2) return p;
   
        for (int i = 2; i < nums.size(); i++) {
            cur = max(pp+nums[i], p);
            pp = p;
            p = cur;
        }
        return cur;
    }
};
