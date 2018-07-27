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

    int minDepth(TreeNode* root) {
        
        // pay attention to the boundary.
        // although (root->right == NULL && root->left == NULL) restricts that no 'NULL' enter the sentence 'minDepth(root->left)',
        // it cannot handle the situation when the tree is empty, which means the first 'root' passed in is NULL, 
        // which does not have 'root->right' and 'root->left' and will result in runtime error.
        if (root == NULL) return 0;
        
        // pay attention to the situation that one of subtrees is empty.
        // in this situation, it's wrong to pick the minimum depth between left subtree and right subtree, or the minimum depth is 0.
        if (root->right == NULL && root->left == NULL) return 1;
        if (root->right == NULL) return minDepth(root->left)+1;
        if (root->left == NULL) return minDepth(root->right)+1;
        
        // when both subtrees are not empty
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};
