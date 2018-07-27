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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) return NULL;
        
        // '.back()' gets the last value in vector
        TreeNode* root = new TreeNode(postorder.back());
        
        // 'find' returns a iterator. Caculate the 'distance' between this iterator and 'begin()' and then get the index.
        vector<int>::iterator pos_iter = find(inorder.begin(), inorder.end(), postorder.back());
        int pos = distance(inorder.begin(), pos_iter);
        
        // pay attention to the index interval. the right side is exclusive.
        vector<int> left_inorder(inorder.begin(), inorder.begin()+pos);
        vector<int> right_inorder(inorder.begin()+pos+1, inorder.end());
        vector<int> left_postorder(postorder.begin(), postorder.begin()+pos);
        vector<int> right_postorder(postorder.begin()+pos, postorder.end()-1);
        
        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);
        
        return root;
    }
};
