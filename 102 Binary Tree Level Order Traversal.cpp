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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> cur;
        
        queue<TreeNode*> visiting;
        queue<TreeNode*> next_visit;
        if (!root) return ans;
        visiting.push(root);
        
        // the adjacent levels cannot use one common queue, for you can't determine where is the boundary of the level.
        // when 'next_visit' is empty, after 'visiting = next_visit', the 'visiting' queue is empty too, so the 'while' loop terminates.
        while (!visiting.empty()) {
            // visit the front value according to the queue.
            TreeNode* node = visiting.front();
            visiting.pop();
            
            //cout << visiting.back()->val << endl;
            if (node) cur.push_back(node->val);
            if (node->left) next_visit.push(node->left);
            if (node->right) next_visit.push(node->right);
            
            if (visiting.empty()) {
                visiting = next_visit;
                ans.push_back(cur);
                
                // clear current vector and the queue of next level.
                cur.clear();
                next_visit = queue<TreeNode*>();
            }
        }
        
        return ans;
    }
};
