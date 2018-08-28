// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        for (int i = 0; i < m-1; i++) pre = pre->next;
        
        ListNode* tail = pre->next, *then = tail->next;
        for (int i = 0; i < n-m; i++) {
            tail->next = then->next;
            then->next = pre->next;
            pre->next = then;
            
            then = tail->next;
        }
        
        return dummy->next;
    }

int main()
{
    vector<int> v= {1,2};
    ListNode* dummy = new ListNode(0);
    ListNode* tmp = dummy;
    for (int i = 0; i < v.size(); i++) {
    	tmp->next = new ListNode(v[i]);
    	
    	tmp = tmp->next;
    	cout << tmp->val << " ";
    }
    cout << endl;
    
    tmp = reverseBetween(dummy->next, 2, 2);
    for (int i = 0; i < v.size(); i++) {
    	cout << tmp->val << " ";
    	tmp = tmp->next;
    }
}

