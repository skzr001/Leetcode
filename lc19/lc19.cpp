/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    //Note says "given n will always be valid". However, when we do this operation, the first thing would be
    //checking whether there is element in the memory.
public://Method 1: Two Pointers, one is fast, the other is slow.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL||n<0) return head;//boundary checking

        ListNode sentinel(0);
        sentinel.next=head;

        ListNode *lp_fast=&sentinel;
        for(int i=0;i<n;i++){
            if(lp_fast->next==NULL) return head;
            lp_fast=lp_fast->next;
        }

        ListNode *lp_slow=&sentinel;

        for(;lp_fast->next!=NULL;lp_slow=lp_slow->next,lp_fast=lp_fast->next);//find the reversal n'th element.

        ListNode *lp_delete=lp_slow->next;
        lp_slow->next=lp_slow->next->next;
        delete lp_delete;

        return sentinel.next;
    }
};






















}