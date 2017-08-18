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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !(head->next)) return head;
        if(k<=0) return head;
        ListNode* node1 = head;
        ListNode* node2 = node1;
        
        int sz = 0;
        while(node1){
        	sz++;
        	node1 = node1->next;
        }
        k = k % sz;
        node1 = head;
        
        for(int i=0;i<k;i++){
            node2 = node2->next;
        }
        queue<int> que;
        for(int i=0;i<k;i++){
            que.push(node2->val);
            node2->val = node1->val;
            node1 = node1->next;
            node2 = node2->next ? node2->next : head;
        }
        while(node1){
        	que.push(node2->val);
            node2->val = que.front();
            que.pop();
            node1 = node1->next;
            node2 = node2->next ? node2->next : head;
        }
        return head;
    }
};
