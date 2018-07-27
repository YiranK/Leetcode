/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int low, int high) {
        if (low > high) return NULL;
        TreeNode* pivot = new TreeNode(nums[(low+high)/2]);
        pivot->left = helper(nums, low, (low+high)/2-1);
        pivot->right = helper(nums, (low+high)/2+1, high);
        return pivot;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        TreeNode* root = helper(nums, 0, nums.size()-1);
        return root;
    }
};
