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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> cur;
        
        queue<TreeNode*> visiting;
        queue<TreeNode*> to_visit;
        
        if (!root) return ans;
        visiting.push(root);
        
        while (!visiting.empty()) {
            TreeNode* node = visiting.front();
            visiting.pop();
            
            if (node) cur.push_back(node->val);
            if (node->left) to_visit.push(node->left);
            if (node->right) to_visit.push(node->right);
            
            if (visiting.empty()) {
                visiting = to_visit;
                ans.push_back(cur);
                cur.clear();
                to_visit = queue<TreeNode*>();
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
