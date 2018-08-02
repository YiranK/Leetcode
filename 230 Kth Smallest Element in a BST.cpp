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
    void traverse(TreeNode* root, vector<int>& sortedTree) {
        if (!root) return;
        if (root->left) traverse(root->left, sortedTree);
        sortedTree.push_back(root->val);
        if (root->right) traverse(root->right, sortedTree);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        
        vector<int> sortedTree;
        traverse(root, sortedTree);
        
        return sortedTree[k-1];
    }
};

// inorder traverse of Binary Search Tree is the sort result of it,
