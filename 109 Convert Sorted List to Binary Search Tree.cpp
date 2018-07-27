/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        // special case 0: (head == NULL).
        if (!head) return NULL;
        
        // special case 1: the length of linked list is 1. 
        if (!head->next) return new TreeNode(head->val);
        
        // use two pointers, 'fast' and 'slow', to determine the middle node.
        // use 'tmp' to record the node before the middle one, for later the linked list will be divide to two parts.
        // notice that '*' should be taken before every variable name.
        ListNode* fast = head, *slow = head, *tmp;
        while (fast && fast->next) {
            fast = fast->next->next;
            tmp = slow;
            slow = slow->next;
        }
        // cut the linked list.
        tmp->next = NULL;
        
        // create current treenode
        TreeNode* root = new TreeNode(slow->val);
        // use right part of linked list.
        root->right = sortedListToBST(slow->next);
        // use left part of linked list.
        root->left = sortedListToBST(head);
        
        return root;
    }
};
