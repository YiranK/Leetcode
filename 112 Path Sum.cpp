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
    vector<int> getSum(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            // if not 'push_back(0)', in next step the sum can not accumulate.
            res.push_back(0);
        } else {
            int val = root->val;
            
            // NOTICE! consider the situation that the node just has one of subtrees specially. like [1, 2], sum = 1, expected FALSE.
            // if the node has right subtree but does not have left tree, the left tree must be dropped and cannot be accumulated.
            if (!(root->right && !root->left)) {
                vector<int> left = getSum(root->left);
                for (int i = 0; i < left.size(); i++) {
                    res.push_back(val + left[i]);
                }
            }
            
            // if the node has left subtress but does not have right tree, the right tree must be dropped and cannot be accumulated.
            if (!(root->left && !root->right)) {
                vector<int> right = getSum(root->right);
                for (int i = 0; i < right.size(); i++) {
                    res.push_back(val + right[i]);
                }
            }
            
            // but when the node does not have left and right tree neither, the value can be accumulated from vector<int> : {0}.
            
        }
        return res;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        // need to handle (root == NULL) specially.
        if (root == NULL) return false;
        
        vector<int> res = getSum(root);
        for (int i = 0; i < res.size(); i++) {
            if (sum == res[i]) return true;
        }
        return false;
    }
};



// better solution
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
    
    bool hasPathSum(TreeNode* root, int sum) {
        // need to handle (root == NULL) specially.
        // also because of this sentence, you need to restrict NULL enter this function.
        // like in (!root->left && root->right), do not forget '&& root->right'.
        if (root == NULL) return false;
        
        // notice that at first minus value of current node.
        int remain = sum - root->val;
        if (remain == 0 && !root->left && !root->right) return true;
        
        if (!root->left && root->right) return hasPathSum(root->right, remain);
        if (!root->right && root->left) return hasPathSum(root->left, remain);
        
        return hasPathSum(root->right, remain) || hasPathSum(root->left, remain);
    }
};
