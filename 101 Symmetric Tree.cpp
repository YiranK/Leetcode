/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// recursive
// time complexity: traverse every node once, O(n)
// space complexity: the number of recursion stack is relavent to the height of the tree,
//                   for in every recursion we visit children of current node, which means nodes in next floor.
//                   In the worst case, the tree is linear, so the height of tree is 'n', O(n)
class Solution {
public:
    // 'left' and 'right' are the symmetric nodes of the tree, not the symmetric nodes of their parent node.
    // the directions of path to two symmetric nodes are always opposite,
    // like, if the path of node 'a' is [left, right, left], then the path of its symmetric node 'b' is [right, left, right].
    bool helper(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left != NULL && right != NULL) {
            return (left->val == right->val) && helper(left->right, right->left) && helper(left->left, right->right);
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return helper(root->left, root->right);
    }
};


// iterate
// use two stack simultaneously to compare two correspounding symmetric nodes.
// time complexity: traverse each node only once, O(n)
// space complexity: every node is pushed into stack once, O(n)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        //return helper(root->left, root->right);
        
        // more simple: in the beginning, just stack 'root' to these two stacks, do not need to push 'root->left' into 'left_stack'.
        stack<TreeNode*> left_stack, right_stack;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        left_stack.push(left);
        right_stack.push(right);
        
        while (!left_stack.empty()) {
            TreeNode* left = left_stack.top();
            TreeNode* right = right_stack.top();
            left_stack.pop();
            right_stack.pop();
            // notice to this! 'NULL' can not be pushed into the stack. Runtime error will occur if not the sentence below.
            if (left == NULL && right == NULL) continue;
            if ((left == NULL || right == NULL) && !(left == NULL && right == NULL)) return false;
            if ((left != NULL && right != NULL) && (left->val != right->val)) return false;
            left_stack.push(left->left);
            right_stack.push(right->right);
            left_stack.push(left->right);
            right_stack.push(right->left);
        }
        return true;
    }
};


// question: 
// 1. why the two way result in different space.
// 2. the recursion uses depth-first, while the iteration uses breadth-first, is that right?
