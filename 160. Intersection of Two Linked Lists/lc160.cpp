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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA=headA;
        ListNode *curB=headB;

        while(curA!=curB){
            curA=(curA==NULL)?curA->next:headB;
            curB=(curB==NULL)?curB->next:headA;
        }
        return curA;
    }
};