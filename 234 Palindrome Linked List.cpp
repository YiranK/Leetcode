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



// O(1) Space
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = head, *tmp;
        
        while (cur) {
            tmp = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = tmp;
        }
        
        return dummy->next;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head || head->next == NULL) return true;
        ListNode* slow = head, *fast = head->next;
        // slow indicates the first node in the second part, no matter if there is one node or are two nodes in the middle.
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        // after while loop, slow indicates the head of second part
        
        // after reverse, the sec points to original tail of linked list,
        // the tail of second part is where origin slow pointer points to.
        // if dual number of nodes in linked list, after reverse, the final of first part points to that of second part,
        // if odd number of nodes in linked list, after reverse, the final of fist part is the same as that of second part.
        ListNode* sec = reverse(slow);
        ListNode* first = head;
        // pay attention that if dual number, there's a condition the first pointer points to the tail of second part,
        // while the second pointer points to NULL, so notice the condition: while(sec && first)
        while (sec && first && sec != first) {
            if (sec->val != first->val) return false;
            // do not forget to move to next!
            sec = sec->next;
            first = first->next;
        }
        return true;
    }
};