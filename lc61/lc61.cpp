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
        if(head==NULL) return NULL;
        int len=1;
        ListNode *left=head, *right=head;

        for(;right->next!=NULL;right=right->next,len++);
        k%=len;
        if(k==0) return head;
        for(int i=0;i<len-k-1;i++,left=left->next);
        right->next=head;
        head=left->next;
        left->next=NULL;
        return head;
    }
};}