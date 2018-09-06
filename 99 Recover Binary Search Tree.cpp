/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// O(n) space
class Solution {
public:
    void replaceVal(TreeNode* root, int a, int b) {
        if (!root) return;
        if (root->val == a) {
            root->val = b;
        } else if (root->val == b) {
            root->val = a;
        }
        if (root->left) replaceVal(root->left, a, b);
        if (root->right) replaceVal(root->right, a, b);  
    }
    
    void buildTree(TreeNode* root, vector<int>& bst) {
        if (!root) return;
        if (root->left) buildTree(root->left, bst);
        bst.push_back(root->val);
        if (root->right) buildTree(root->right, bst);
    }
    void recoverTree(TreeNode* root) {
        vector<int> bst;
        buildTree(root, bst);
        vector<int> swap;
        for (int i = 0; i < bst.size()-1; i++) {
            // bst[i] = bst[i+1] - bst[i];
            if (bst[i+1] - bst[i] < 0) {
                if (swap.empty()) {
                    swap.push_back(i);
                } else {
                    swap.push_back(i+1);
                }
            }
        }
        if (swap.size()==1) swap.push_back(swap[0]+1);
        cout << bst[swap[0]] << " " << bst[swap[1]] << endl;
        replaceVal(root, bst[swap[0]], bst[swap[1]]);
    }
};
