/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode* cur = head;
        RandomListNode* dummy = new RandomListNode(-1);
        
        // first round: create copy.
        // create copy of each node perfectly behind each node.
        while (cur) {
            RandomListNode* node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            
            cur = cur->next->next;
        }
        
        
        // second round: link 'random'  pointer.
        // link 'random' pointer, since the copy of each node is perfectly behind the original node.
        // if the 'random' pointer of node A points to a node B, the the copy of node A points to B->next.
        cur = head;
        while (cur) {
            // cur->next: the copy node of cur.
            // cur->random->next: the copy node of cur->random.
            if (cur->random) cur->next->random = cur->random->next;
            
            cur = cur->next->next;
        }
        
        // third round: extract new linked list.
        // don't forget this step.
        cur = head;
        RandomListNode* tail = dummy;
        while (cur) {
            tail->next = cur->next;
            tail = tail->next; // error once occurred if this sentence missed. pay attention to move of 'tail'.
                               // especially when you set value of 'tail->next', consider if 'tail' needs move to its 'next'.
            cur->next = tail->next;
            
            
            cur = cur->next;
            
        }
        
        
        return dummy->next;
    }
};
