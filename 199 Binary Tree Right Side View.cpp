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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        queue<TreeNode*> toVisit;
        toVisit.push(root);
        while (!toVisit.empty()) {
            ans.push_back(toVisit.back()->val);
            
            int toVisitSize = toVisit.size();
            
            while (toVisitSize--) {
                TreeNode* node = toVisit.front();
                toVisit.pop();
                
                if (node->left) toVisit.push(node->left);
                if (node->right) toVisit.push(node->right);
            }
        }
        return ans;
    }
};

// error-prone point:
// 1. queue<TreeNode*>, pay attention to '*'!!
// 2. 'if (node->left) toVisit.push(node->left);' pay attention to (node->left). do not add '!' before this pointer silly, haha.
