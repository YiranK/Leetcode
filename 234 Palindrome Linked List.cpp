/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> nums;
        ListNode* tmp = head;
        int count = 0, i = 0;
        while (tmp) {
            count++;
            tmp = tmp->next;
        }
        
        // if (count % 2) return false;
        tmp = head;
        for (; i < double(count)/2; i++) {
            nums.push(tmp->val);
            tmp = tmp->next;
        }
        // cout << nums.size();
        if (count % 2) nums.pop();
        for (; i < count; i++) {
            // cout << tmp->val << endl;
            // cout << nums.top();
            if (nums.top() != tmp->val) return false;
            nums.pop();
            tmp = tmp->next;
        }
        return true;
    }
};

// error-prone:
// 1. double(count)
// 2. when count == odd, it can be palindrome too