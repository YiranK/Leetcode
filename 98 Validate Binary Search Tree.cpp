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
    // because all nodes in left subtree must be less than the root value,
    // we need recursion to traverse every node in left subtree to check if it is less,
    // and we make root value 'val' fixed in this function.
    bool isValidLeft(TreeNode* tmp, int val) {
        if (tmp == NULL) return true;
        return (tmp->val < val) && isValidLeft(tmp->left, val) && isValidLeft(tmp->right, val);
    }
    
    // the right subtree cannot combine with the left subtree in one funtion,
    // because they are extended in two distinct branch.
    bool isValidRight(TreeNode* tmp, int val) {
        if (tmp == NULL) return true;
        return (tmp->val > val) && isValidRight(tmp->left, val) && isValidRight(tmp->right, val);
    }
    
    // for every node value, we need to compare the substree with it.
    // So it's neccessary to recursive this function to traverse every node.
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        return isValidLeft(root->left, root->val) && isValidRight(root->right, root->val) &&
            isValidBST(root->left) && isValidBST(root->right);
    }
};
