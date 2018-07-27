/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cmath>
class Solution {
public:
    int getHeight(TreeNode* cur) {
        if (cur == NULL) return 0;
        return max(getHeight(cur->left), getHeight(cur->right))+1;
    }
    
    bool isBalanced(TreeNode* root) {
        // notice this sentence.
        if (root == NULL) return true;
        if (abs(getHeight(root->left)-getHeight(root->right))>1) return false;
        
        // notice that every node should satisfy the height-balance requirement,
        // so we need to use recursion to traverse every node.
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
