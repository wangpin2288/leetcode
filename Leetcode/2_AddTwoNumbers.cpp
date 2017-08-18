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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* phead = new ListNode(0);
        int extra = 0;
        ListNode* cur = phead;
        while(l1 || l2 || extra){
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum/10;
            ListNode* newnode = new ListNode(sum%10);
            newnode->next = NULL;
            cur->next = newnode;
            cur = cur->next;
            l1 = (l1 ? l1->next : l1);
            l2 = (l2 ? l2->next : l2);
        }
        return phead->next;
    }
};
