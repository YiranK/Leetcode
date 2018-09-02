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
    void visit(TreeNode* root, vector<int>& res) {
        if (!root) return;
        if (root) res.push_back(root->val);
        if (root->left) visit(root->left, res);
        if (root->right) visit(root->right, res);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        visit(root, res);
        return res;
    }
};


// iteratively, use Stack,, not Queue
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* head) {
        if (!head) return vector<int>();
        vector<int> res;
        
        stack<TreeNode*> tovisit;
        tovisit.push(head);
        
        while (!tovisit.empty()) {
            TreeNode* root = tovisit.top();
            tovisit.pop();
            res.push_back(root->val);
            if (root->right) tovisit.push(root->right);
            if (root->left) tovisit.push(root->left);
        }
               
        return res;
    }
};
