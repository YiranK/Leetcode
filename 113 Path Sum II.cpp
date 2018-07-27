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
    void findPath(vector<vector<int>>& ans, vector<int> cur, TreeNode* root, int tar) {
        if (root == NULL) return;
        // notice the definition of 'leaf': do not have children, which means (root->left == NULL && root->right == NULL).
        
        cur.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL && (tar == root->val)) {
            ans.push_back(cur);
        } else {
            findPath(ans, cur, root->left, tar - root->val);
            findPath(ans, cur, root->right, tar - root->val);
            // if the cur is passed by refernce, it needs pop_back() here, which is the same with backtracking.
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> cur;
        if (root == NULL) return ans;
        
        findPath(ans, cur, root, sum);
        return ans;
    }
};
