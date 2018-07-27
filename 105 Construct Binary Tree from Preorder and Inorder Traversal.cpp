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
    // void printvector(vector<int> a) {
    //     for (int i = 0; i < a.size(); i++) {
    //         cout << a[i] << " ";
    //     }
    //     cout << endl;
    // }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if (pre.empty()) return NULL;

        TreeNode* cur = new TreeNode(pre[0]);

        int i;
        for (i = 0; i < in.size(); i++) {
            if (in[i] == pre[0]) break;
        }
        
        // NOTICE! the index interval is left inclusive but right exclusive!
        // (in.begin(), in.begin()+i) means inorder[0,i), also inorder[0,i-1].
        vector<int> left_in(in.begin(), in.begin()+i);
        vector<int> right_in(in.begin()+i+1, in.end());
        vector<int> left_pre(pre.begin()+1, pre.begin()+i+1);
        vector<int> right_pre(pre.begin()+i+1, pre.end());
        
        
        // print vector and check
//         cout << pre[0] << " idx: " << i << endl;
//         cout << "origin pre: ";
//         printvector(pre);
//         cout << "left_pre: ";
//         printvector(left_pre);
//         cout << "right_pre: ";
//         printvector(right_pre);
//         cout << endl;
        
//         cout << "origin in: ";
//         printvector(in);
//         cout << "left_in: ";
//         printvector(left_in);
//         cout << "right_in: ";
//         printvector(right_in);
//         cout << endl << endl;
        
        cur->left = buildTree(left_pre, left_in);
        cur->right = buildTree(right_pre, right_in);
        
        return cur;
    }
};
