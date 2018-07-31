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
    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        // pay attention.
        while (left && right) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
                tail = tail->next;
            } else {
                tail->next = right;
                right = right->next;
                tail = tail->next;
            }
            tail->next = left ? left : right;
        }
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // the situation of just 2 nodes do not need special handle.
        // if (!head->next->next) {
        //     if (head->val <= head->next->val) {
        //         return head;
        //     } else {
        //         ListNode* newHead = head->next;
        //         head->next = NULL;
        //         newHead->next = head;
        //         return newHead;
        //     }
        // }
        
        // find the middle nodes of list.
        ListNode* fast = head, *slow = head, *tmp = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            tmp = slow;
            slow = slow->next;
        }
        
        // cut to 2 parts
        tmp->next = NULL;
        
        // sort list partly.
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        // better to hand
        ListNode* newHead = mergeList(left, right);
        return newHead;

        
        // better to handle the merge process in a specific function, see above.
//         // fake head. instead, the true head is newHead->next.
//         ListNode* newHead = new ListNode(0);
//         ListNode* tail = newHead;

//         while (left || right) {
//             bool notnull = (tail != NULL);
//             //cout << "not null: " << notnull << endl;
//             //cout << tail->val << endl;
//             //cout <<  left->val <<  "< " << right->val << endl;
            
//             if (!left) {tail->next = right; break;}
//             if (!right) {tail->next = left; break;}
            
//             if (left!=NULL && right!=NULL) {
//                 if (left->val <= right->val) {
//                     //cout <<  left->val <<  "< " << right->val << endl;
//                     tail->next = left; 
//                     left = left->next; 
//                 } else {
//                     //cout <<  left->val <<  "> " << right->val << endl;
//                     tail->next = right;
//                     right = right->next;
//                 }
//             }
//             if (tail->next) tail = tail->next;
            
            
//         }
                 
    }
};
