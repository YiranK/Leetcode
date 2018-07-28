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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue<TreeNode*> tovisit;
        bool rever = false;
        if (!root) return ans;
        tovisit.push(root);
        
        while (!tovisit.empty()) {
            vector<int> cur;
            
            // pop queue according to level size.
            int cur_level_size = tovisit.size();
            while (cur_level_size--) {
                TreeNode* node = tovisit.front();
                tovisit.pop();
                if (node) cur.push_back(node->val);
                if (node->left) tovisit.push(node->left);
                if (node->right) tovisit.push(node->right);
            }
            
            // reverse according to the flag.
            if (rever) reverse(cur.begin(), cur.end());
            // change the flag alternatively.
            rever = (rever==false);
            
            ans.push_back(cur);
        }
        
        return ans;
    }
};


// dfs solution
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
    // use dfs to traverse the tree, and store the nodes of each level in corresponding level vector.
    // need to pass number 'level' to 'dfs' function, to indicate the index of level vector.
    void dfs(vector<vector<int>>& ans, TreeNode* root, int level) {
        if (!root) return;
        // if there is not this level vector in 'vector<vector<int>>' yet, push a new empty one.
        if (level >= ans.size()) ans.push_back(vector<int>());
        
        // alternatively reverse by using the level index.
        if (level % 2) {
            ans[level].insert(ans[level].begin(), root->val);   
        } else {     
            ans[level].push_back(root->val);
        }
        
        // recursively traverse each node in the tree, and add the 'level' accordingly.
        if (!(!root->left && !root->right)) {
            dfs(ans, root->left, level+1);
            dfs(ans, root->right, level+1);
        }
    }
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        bool rever = false;
        if (!root) return ans;
        
        dfs(ans, root, 0);     
        return ans;
    }
};
